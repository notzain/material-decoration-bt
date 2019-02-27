#pragma once

// KDecoration
#include <KDecoration2/DecorationButton>

namespace Material
{

class Decoration;

class ApplicationMenuButton : public KDecoration2::DecorationButton
{
    Q_OBJECT

public:
    ApplicationMenuButton(Decoration *decoration, QObject *parent = nullptr);
    ~ApplicationMenuButton() override;

    void paint(QPainter *painter, const QRect &repaintRegion) override;

private:
    QColor backgroundColor() const;
    QColor foregroundColor() const;
};

} // namespace Material
