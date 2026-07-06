#pragma once

#include <QDialog>

class QComboBox;

class SerialDialog final : public QDialog
{
public:

    explicit SerialDialog(QWidget* parent = nullptr);

    ~SerialDialog() override = default;

    [[nodiscard]]
    QString port_name() const;

    [[nodiscard]]
    qint32 baud_rate() const;

private:

    void initialize_dialog();

private:

    QComboBox* port_box_;

    QComboBox* baud_box_;

};