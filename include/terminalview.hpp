#pragma once

#include <QPaintEvent>
#include <QWidget>

class TerminalView final : public QWidget
{
public:

    explicit TerminalView(QWidget* parent = nullptr);

    ~TerminalView() override = default;

protected:

    void paintEvent(QPaintEvent* event) override;

private:

    void initialize_terminal();

private:

    QString display_text_;

};