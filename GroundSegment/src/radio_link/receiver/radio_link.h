#ifndef RADIO_LINK_H
#define RADIO_LINK_H
#include <QObject>

class RadioLink : public QObject {
    Q_OBJECT
public:
    explicit RadioLink(QObject *parent = nullptr);

};

#endif // RADIO_LINK_H
