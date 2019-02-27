#pragma once

// KDecoration
#include <KDecoration2/DecorationButton>

namespace Material
{

class Decoration;

class KeepAboveButton : public KDecoration2::DecorationButton
{
    Q_OBJECT

public:
    KeepAboveButton(Decoration *decoration, QObject *parent = nullptr);
    ~KeepAboveButton() override;

    void paint(QPainter *painter, const QRect &repaintRegion) override;

private:
    QColor backgroundColor() const;
    QColor foregroundColor() const;
};

} // namespace Material
