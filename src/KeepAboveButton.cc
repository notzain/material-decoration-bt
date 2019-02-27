// own
#include "KeepAboveButton.h"
#include "Decoration.h"

// KDecoration
#include <KDecoration2/DecoratedClient>

// KF
#include <KColorUtils>

// Qt
#include <QPainter>

namespace Material
{

KeepAboveButton::KeepAboveButton(Decoration *decoration, QObject *parent)
    : DecorationButton(KDecoration2::DecorationButtonType::KeepAbove, decoration, parent)
{
    connect(this, &KeepAboveButton::hoveredChanged, this,
        [this] {
            update();
        });

    const int titleBarHeight = decoration->titleBarHeight();
    const QSize size(qRound(titleBarHeight * 1.33), titleBarHeight);
    setGeometry(QRect(QPoint(0, 0), size));
    setVisible(true);
}

KeepAboveButton::~KeepAboveButton()
{
}

void KeepAboveButton::paint(QPainter *painter, const QRect &repaintRegion)
{
    Q_UNUSED(repaintRegion)

    const QRectF buttonRect = geometry();
    QRectF keepAboveRect = QRectF(0, 0, 10, 10);
    keepAboveRect.moveCenter(buttonRect.center().toPoint());

    painter->save();

    painter->setRenderHints(QPainter::Antialiasing, false);

    // Background.
    painter->setPen(Qt::NoPen);
    painter->setBrush(backgroundColor());
    painter->drawRect(buttonRect);

    if (isChecked()) {
        const auto *deco = qobject_cast<Decoration *>(decoration());
        auto *decoratedClient = deco->client().data();

        painter->setPen( decoratedClient->color(
            KDecoration2::ColorGroup::Warning,
            KDecoration2::ColorRole::Foreground
        ));
    } else {
        painter->setPen(foregroundColor());
    }

    painter->setBrush(Qt::NoBrush);

    const QPointF topMiddle {keepAboveRect.center().x(), keepAboveRect.top()};
    painter->drawLine(keepAboveRect.bottomLeft(), topMiddle);
    painter->drawLine(topMiddle, keepAboveRect.bottomRight());

    painter->restore();
}

QColor KeepAboveButton::backgroundColor() const
{
    const auto *deco = qobject_cast<Decoration *>(decoration());
    if (!deco) {
        return {};
    }

    if (isPressed()) {
        return QColor(0,0,0, 255 * 0.3);
    }

    if (isHovered()) {
        return QColor(0,0,0, 255 * 0.2);
    }

    return Qt::transparent;
}

QColor KeepAboveButton::foregroundColor() const
{
    const auto *deco = qobject_cast<Decoration *>(decoration());
    if (!deco) {
        return {};
    }

    return deco->titleBarForegroundColor();
}

} // namespace Material
