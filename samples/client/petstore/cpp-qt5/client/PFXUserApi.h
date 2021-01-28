/**
 * OpenAPI Petstore
 * This is a sample server Petstore server. For this sample, you can use the api key `special-key` to test the authorization filters.
 *
 * The version of the OpenAPI document: 1.0.0
 *
 * NOTE: This class is auto generated by OpenAPI Generator (https://openapi-generator.tech).
 * https://openapi-generator.tech
 * Do not edit the class manually.
 */

#ifndef PFX_PFXUserApi_H
#define PFX_PFXUserApi_H

#include "PFXHttpRequest.h"
#include "PFXServerConfiguration.h"

#include "PFXUser.h"
#include <QList>
#include <QString>

#include <QObject>
#include <QByteArray>
#include <QStringList> 
#include <QList>
#include <QNetworkAccessManager>

namespace test_namespace {

class PFXUserApi : public QObject {
    Q_OBJECT

public:
    PFXUserApi(const QString &scheme = "http", const QString &host = "petstore.swagger.io", int port = 0, const QString &basePath = "/v2", const int timeOut = 0);
    ~PFXUserApi();

    void initializeServerConfigs();
    int setDefaultServerValue(int serverIndex,const QString &operation, const QString &variable,const QString &val);
    void setServerIndex(const QString &operation, int serverIndex);
    void setScheme(const QString &scheme);
    void setHost(const QString &host);
    void setPort(int port);
    void setApiKey(const QString &apiKeyName, const QString &apiKey);
    void setBearerToken(const QString &token);
    void setUsername(const QString &username);
    void setPassword(const QString &password);
    void setBasePath(const QString &basePath);
    void setTimeOut(const int timeOut);
    void setWorkingDirectory(const QString &path);
    void setNetworkAccessManager(QNetworkAccessManager* manager);
    void addHeaders(const QString &key, const QString &value);
    void enableRequestCompression();
    void enableResponseCompression();
    void abortRequests();
    QString getParamStylePrefix(QString style);
    QString getParamStyleSuffix(QString style);
    QString getParamStyleDelimiter(QString style, QString name, bool isExplode);


    void createUser(const PFXUser &body);
    void createUsersWithArrayInput(const QList<PFXUser> &body);
    void createUsersWithListInput(const QList<PFXUser> &body);
    void deleteUser(const QString &username);
    void getUserByName(const QString &username);
    void loginUser(const QString &username, const QString &password);
    void logoutUser();
    void updateUser(const QString &username, const PFXUser &body);

private:
    QString _scheme, _host;
    int _port;
    QString _basePath;
    QMap<QString,int> _serverIndices;
    QMap<QString,QList<PFXServerConfiguration>> _serverConfigs;
    QMap<QString, QString> _apiKeys;
    QString _bearerToken;
    QString _username;
    QString _password;
    int _timeOut;
    QString _workingDirectory;
    QNetworkAccessManager* _manager;
    QMap<QString, QString> defaultHeaders;
    bool isResponseCompressionEnabled;
    bool isRequestCompressionEnabled;

    void createUserCallback(PFXHttpRequestWorker *worker);
    void createUsersWithArrayInputCallback(PFXHttpRequestWorker *worker);
    void createUsersWithListInputCallback(PFXHttpRequestWorker *worker);
    void deleteUserCallback(PFXHttpRequestWorker *worker);
    void getUserByNameCallback(PFXHttpRequestWorker *worker);
    void loginUserCallback(PFXHttpRequestWorker *worker);
    void logoutUserCallback(PFXHttpRequestWorker *worker);
    void updateUserCallback(PFXHttpRequestWorker *worker);

signals:

    void createUserSignal();
    void createUsersWithArrayInputSignal();
    void createUsersWithListInputSignal();
    void deleteUserSignal();
    void getUserByNameSignal(PFXUser summary);
    void loginUserSignal(QString summary);
    void logoutUserSignal();
    void updateUserSignal();

    void createUserSignalFull(PFXHttpRequestWorker *worker);
    void createUsersWithArrayInputSignalFull(PFXHttpRequestWorker *worker);
    void createUsersWithListInputSignalFull(PFXHttpRequestWorker *worker);
    void deleteUserSignalFull(PFXHttpRequestWorker *worker);
    void getUserByNameSignalFull(PFXHttpRequestWorker *worker, PFXUser summary);
    void loginUserSignalFull(PFXHttpRequestWorker *worker, QString summary);
    void logoutUserSignalFull(PFXHttpRequestWorker *worker);
    void updateUserSignalFull(PFXHttpRequestWorker *worker);

    void createUserSignalE(QNetworkReply::NetworkError error_type, QString error_str);
    void createUsersWithArrayInputSignalE(QNetworkReply::NetworkError error_type, QString error_str);
    void createUsersWithListInputSignalE(QNetworkReply::NetworkError error_type, QString error_str);
    void deleteUserSignalE(QNetworkReply::NetworkError error_type, QString error_str);
    void getUserByNameSignalE(PFXUser summary, QNetworkReply::NetworkError error_type, QString error_str);
    void loginUserSignalE(QString summary, QNetworkReply::NetworkError error_type, QString error_str);
    void logoutUserSignalE(QNetworkReply::NetworkError error_type, QString error_str);
    void updateUserSignalE(QNetworkReply::NetworkError error_type, QString error_str);

    void createUserSignalEFull(PFXHttpRequestWorker *worker, QNetworkReply::NetworkError error_type, QString error_str);
    void createUsersWithArrayInputSignalEFull(PFXHttpRequestWorker *worker, QNetworkReply::NetworkError error_type, QString error_str);
    void createUsersWithListInputSignalEFull(PFXHttpRequestWorker *worker, QNetworkReply::NetworkError error_type, QString error_str);
    void deleteUserSignalEFull(PFXHttpRequestWorker *worker, QNetworkReply::NetworkError error_type, QString error_str);
    void getUserByNameSignalEFull(PFXHttpRequestWorker *worker, QNetworkReply::NetworkError error_type, QString error_str);
    void loginUserSignalEFull(PFXHttpRequestWorker *worker, QNetworkReply::NetworkError error_type, QString error_str);
    void logoutUserSignalEFull(PFXHttpRequestWorker *worker, QNetworkReply::NetworkError error_type, QString error_str);
    void updateUserSignalEFull(PFXHttpRequestWorker *worker, QNetworkReply::NetworkError error_type, QString error_str);

    void abortRequestsSignal(); 
};

} // namespace test_namespace
#endif
