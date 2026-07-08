#include "serialmanager.hpp"

#include <QDebug>
#include <QMessageBox>
#include <QByteArray>

SerialManager::SerialManager(QObject* parent)
    : QObject(parent)
{
    connect(
        &serial_,
        &QSerialPort::readyRead,
        this,
        &SerialManager::read_serial);
}

bool SerialManager::connect_port(
    const QString& port_name,
    qint32 baud_rate)
{
    if (serial_.isOpen())
        serial_.close();

    serial_.setPortName(port_name);

    serial_.setBaudRate(baud_rate);

    if (!serial_.open(QIODevice::ReadWrite))
        return false;

    emit connected_changed(true);

    return true;
}

void SerialManager::disconnect_port()
{
    if (!serial_.isOpen())
        return;

    serial_.close();

    emit connected_changed(false);
}

bool SerialManager::connected() const
{
    return serial_.isOpen();
}

void SerialManager::send(
    const QByteArray& data)
{
    if (!serial_.isOpen())
        return;

    serial_.write(data);
}

void SerialManager::read_serial()
{
    rx_buffer_.append(
        serial_.readAll());

    while (true)
    {
        const qsizetype newline =
            rx_buffer_.indexOf('\n');

        if (newline < 0)
            break;

        QByteArray line =
            rx_buffer_.left(newline);

        rx_buffer_.remove(
            0,
            newline + 1);

        if (!line.isEmpty() &&
            line.back() == '\r')
        {
            line.chop(1);
        }

        emit data_received(line);
    }
}

void SerialManager::send_line(const QString& text)
{
    if (!serial_.isOpen())
        return;

    serial_.write(text.toUtf8() + '\n');
}