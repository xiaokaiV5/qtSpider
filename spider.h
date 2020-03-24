#ifndef SPIDER_H
#define SPIDER_H

#include <QNetworkAccessManager>
#include <QObject>
class Spider :public QObject
{
	Q_OBJECT
public:
	Spider(QString urlStr);
	~Spider();
	int spiderStart();

public slots:
	int replay_finished(QNetworkReply *reply);
private:
	QNetworkAccessManager *mananger;

private:
	
	QByteArray web_data;
	QUrl *url;
};


#endif