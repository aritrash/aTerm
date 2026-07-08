#pragma once

#include <QObject>
#include <QSerialPort>
#include <QByteArray>

class SerialManager final : public QObject
{
    Q_OBJECT

public:

    explicit SerialManager(QObject* parent = nullptr);

    ~SerialManager() override = default;

    bool connect_port(const QString& port_name,
                      qint32 baud_rate);

    void disconnect_port();

    bool connected() const;

    void send(const QByteArray& data);

    void send_line(const QString& text);

signals:

    void data_received(const QByteArray& data);

    void connected_changed(bool connected);

private slots:

    void read_serial();

private:

    QSerialPort serial_;
    QByteArray rx_buffer_;
};