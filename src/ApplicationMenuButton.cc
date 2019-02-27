// own
#include "ApplicationMenuButton.h"
#include "Decoration.h"

// KDecoration
#include <KDecoration2/DecoratedClient>

// KF
#include <KColorUtils>

// Qt
#include <QPainter>

namespace Material
{

ApplicationMenuButton::ApplicationMenuButton(Decoration *decoration, QObject *parent)
    : DecorationButton(KDecoration2::DecorationButtonType::ApplicationMenu, decoration, parent)
{
    auto *decoratedClient = decoration->client().data();
    connect(this, &ApplicationMenuButton::hoveredChanged, this,
        [this] {
            update();
        });

    const int titleBarHeight = decoration->titleBarHeight();
    const QSize size(qRound(titleBarHeight * 1.33), titleBarHeight);
    setGeometry(QRect(QPoint(0, 0), size));
    setVisible(decoratedClient->hasApplicationMenu());
}

ApplicationMenuButton::~ApplicationMenuButton()
{
}

void ApplicationMenuButton::paint(QPainter *painter, const QRect &repaintRegion)
{
    Q_UNUSED(repaintRegion)

    const QRectF buttonRect = geometry();
    QRectF menuRect = QRectF(0, 0, 10, 10);
    menuRect.moveCenter(buttonRect.center().toPoint());

    painter->save();

    painter->setRenderHints(QPainter::Antialiasing, false);

    // Background.
    painter->setPen(Qt::NoPen);
    painter->setBrush(backgroundColor());
    painter->drawRect(buttonRect);

    // Foreground.
    painter->setPen(foregroundColor());
    painter->setBrush(Qt::NoBrush);

    const auto stepSize = menuRect.height() / 2;
    
    for (int i = 0; i < 3; ++i) {
        const QPointF left { menuRect.left(), menuRect.top() + i * stepSize };
        const QPointF right { menuRect.right(), menuRect.top() + i * stepSize };

        painter->drawLine(left, right);
    }

    painter->restore();
}

QColor ApplicationMenuButton::backgroundColor() const
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

QColor ApplicationMenuButton::foregroundColor() const
{
    const auto *deco = qobject_cast<Decoration *>(decoration());
    if (!deco) {
        return {};
    }

    return deco->titleBarForegroundColor();
}

} // namespace Material
