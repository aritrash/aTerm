#include "serialdialog.hpp"

#include <QComboBox>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QPushButton>

SerialDialog::SerialDialog(QWidget* parent)
    : QDialog(parent),
      port_box_(nullptr),
      baud_box_(nullptr)
{
    initialize_dialog();
}

void SerialDialog::initialize_dialog()
{
    setWindowTitle("Serial Connection");

    setFixedSize(320, 160);

    setModal(true);

    port_box_ = new QComboBox(this);

    for (int port = 1; port <= 9; ++port)
    {
        port_box_->addItem(
            QString("COM%1").arg(port));
    }

    port_box_->setCurrentText("COM5");

    baud_box_ = new QComboBox(this);

    baud_box_->addItems(
    {
        "2400",
        "4800",
        "9600",
        "19200",
        "38400",
        "57600",
        "115200",
        "230400",
        "460800",
        "921600"
    });

    baud_box_->setCurrentText("115200");

    auto* layout = new QFormLayout(this);

    layout->addRow("COM Port", port_box_);

    layout->addRow("Baud Rate", baud_box_);

    auto* buttons = new QDialogButtonBox(
        QDialogButtonBox::Ok |
        QDialogButtonBox::Cancel,
        this);

    buttons->button(QDialogButtonBox::Ok)
        ->setText("Connect");

    connect(
        buttons,
        &QDialogButtonBox::accepted,
        this,
        &QDialog::accept);

    connect(
        buttons,
        &QDialogButtonBox::rejected,
        this,
        &QDialog::reject);

    layout->addWidget(buttons);

    setLayout(layout);
}

QString SerialDialog::port_name() const
{
    return port_box_->currentText();
}

qint32 SerialDialog::baud_rate() const
{
    return baud_box_->currentText().toInt();
}