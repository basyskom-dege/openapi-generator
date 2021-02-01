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

#include "PFXStoreApi.h"
#include "PFXHelpers.h"
#include "PFXServerConfiguration.h"
#include <QJsonArray>
#include <QJsonDocument>

namespace test_namespace {

PFXStoreApi::PFXStoreApi(const QString &scheme, const QString &host, int port, const QString &basePath, const int timeOut)
    : _scheme(scheme),
      _host(host),
      _port(port),
      _basePath(basePath),
      _timeOut(timeOut),
      _manager(nullptr),
      isResponseCompressionEnabled(false),
      isRequestCompressionEnabled(false) {
      initializeServerConfigs();
      }

PFXStoreApi::~PFXStoreApi() {
}

void PFXStoreApi::initializeServerConfigs(){

//Default server
QList<PFXServerConfiguration> defaultConf = QList<PFXServerConfiguration>();
//varying endpoint server 
QList<PFXServerConfiguration> serverConf = QList<PFXServerConfiguration>();
defaultConf.append(PFXServerConfiguration(
    "http://petstore.swagger.io/v2",
    "No description provided",
    QMap<QString, PFXServerVariable>()));
_serverConfigs.insert("deleteOrder",defaultConf);
_serverIndices.insert("deleteOrder",0);

_serverConfigs.insert("getInventory",defaultConf);
_serverIndices.insert("getInventory",0);

_serverConfigs.insert("getOrderById",defaultConf);
_serverIndices.insert("getOrderById",0);

_serverConfigs.insert("placeOrder",defaultConf);
_serverIndices.insert("placeOrder",0);


}

/**
* returns 0 on success and -1, -2 or -3 on failure.
* -1 when the variable does not exist and -2 if the value is not defined in the enum and -3 if the operation or server index is not found 
*/
int PFXStoreApi::setDefaultServerValue(int serverIndex, const QString &operation, const QString &variable, const QString &value){
    auto it = _serverConfigs.find(operation);
    if(it != _serverConfigs.end() && serverIndex < it.value().size() ){
      return _serverConfigs[operation][serverIndex].setDefaultValue(variable,value);
    }
    return -3;
}
void PFXStoreApi::setServerIndex(const QString &operation, int serverIndex){
    if(_serverIndices.contains(operation) && serverIndex < _serverConfigs.find(operation).value().size() )
        _serverIndices[operation] = serverIndex;
}

void PFXStoreApi::setScheme(const QString &scheme) {
    _scheme = scheme;
}

void PFXStoreApi::setHost(const QString &host) {
    _host = host;
}

void PFXStoreApi::setPort(int port) {
    _port = port;
}

void PFXStoreApi::setApiKey(const QString &apiKeyName, const QString &apiKey){
    _apiKeys.insert(apiKeyName,apiKey);
}

void PFXStoreApi::setBearerToken(const QString &token){
    _bearerToken = token;
}

void PFXStoreApi::setUsername(const QString &username) {
    _username = username;
}

void PFXStoreApi::setPassword(const QString &password) {
    _password = password;
}

void PFXStoreApi::setBasePath(const QString &basePath) {
    _basePath = basePath;
}

void PFXStoreApi::setTimeOut(const int timeOut) {
    _timeOut = timeOut;
}

void PFXStoreApi::setWorkingDirectory(const QString &path) {
    _workingDirectory = path;
}

void PFXStoreApi::setNetworkAccessManager(QNetworkAccessManager* manager) {
    _manager = manager;  
}

void PFXStoreApi::addHeaders(const QString &key, const QString &value) {
    defaultHeaders.insert(key, value);
}

void PFXStoreApi::enableRequestCompression() {
    isRequestCompressionEnabled = true;
}

void PFXStoreApi::enableResponseCompression() {
    isResponseCompressionEnabled = true;
}

void PFXStoreApi::abortRequests(){
    emit abortRequestsSignal();
}

QString PFXStoreApi::getParamStylePrefix(QString style){

        if(style == "matrix"){ 
            return ";";
        }else if(style == "label"){
            return ".";
        }else if(style == "form"){
            return "&"; 
        }else if(style == "simple"){
            return "";
        }else if(style == "spaceDelimited"){
            return "&"; 
        }else if(style == "pipeDelimited"){
            return "&"; 
        }else
            return "none";
}

QString PFXStoreApi::getParamStyleSuffix(QString style){

        if(style == "matrix"){ 
            return "=";
        }else if(style == "label"){
            return "";
        }else if(style == "form"){
            return "=";
        }else if(style == "simple"){
            return "";
        }else if(style == "spaceDelimited"){
            return "=";
        }else if(style == "pipeDelimited"){
            return "=";
        }else
            return "none";
}

QString PFXStoreApi::getParamStyleDelimiter(QString style, QString name, bool isExplode){

        if(style == "matrix"){ 
            return (isExplode) ? ";" + name + "=" : ",";

        }else if(style == "label"){
            return (isExplode) ? "." : ",";

        }else if(style == "form"){
            return (isExplode) ? "&" + name + "=" : ","; 

        }else if(style == "simple"){
            return ",";
        }else if(style == "spaceDelimited"){
            return (isExplode) ? "&" + name + "=" : " ";

        }else if(style == "pipeDelimited"){
            return (isExplode) ? "&" + name + "=" : "|";

        }else if(style == "deepObject"){
            return (isExplode) ? "&" : "none";

        }else
            return "none";
}

void PFXStoreApi::deleteOrder(const QString &order_id) {
    QString fullPath = QString(_serverConfigs["deleteOrder"][_serverIndices.value("deleteOrder")].URL()+"/store/order/{orderId}");
    
    QString order_idPathParam("{");
    order_idPathParam.append("orderId").append("}");
    QString pathPrefix, pathSuffix, pathDelimiter;
    QString pathStyle = "";    
    if(pathStyle == "") 
        pathStyle = "simple";
    pathPrefix = getParamStylePrefix(pathStyle);
    pathSuffix = getParamStyleSuffix(pathStyle);
    pathDelimiter = getParamStyleDelimiter(pathStyle, "orderId", false);
    QString paramString = (pathStyle == "matrix") ? pathPrefix+"orderId"+pathSuffix : pathPrefix;
    fullPath.replace(order_idPathParam, paramString+QUrl::toPercentEncoding(::test_namespace::toStringValue(order_id)));


    PFXHttpRequestWorker *worker = new PFXHttpRequestWorker(this, _manager);
    worker->setTimeOut(_timeOut);
    worker->setWorkingDirectory(_workingDirectory);
    PFXHttpRequestInput input(fullPath, "DELETE");

    foreach (QString key, this->defaultHeaders.keys()) { input.headers.insert(key, this->defaultHeaders.value(key)); }

    connect(worker, &PFXHttpRequestWorker::on_execution_finished, this, &PFXStoreApi::deleteOrderCallback);
    connect(this, &PFXStoreApi::abortRequestsSignal, worker, &QObject::deleteLater); 
    worker->execute(&input);
}

void PFXStoreApi::deleteOrderCallback(PFXHttpRequestWorker *worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    } else {
        msg = "Error: " + worker->error_str;
        error_str = QString("%1, %2").arg(worker->error_str).arg(QString(worker->response));
    }
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit deleteOrderSignal();
        emit deleteOrderSignalFull(worker);
    } else {
        emit deleteOrderSignalE(error_type, error_str);
        emit deleteOrderSignalEFull(worker, error_type, error_str);
    }
}

void PFXStoreApi::getInventory() {
    QString fullPath = QString(_serverConfigs["getInventory"][_serverIndices.value("getInventory")].URL()+"/store/inventory");
    
    if(_apiKeys.contains("api_key")){
        addHeaders("api_key",_apiKeys.find("api_key").value());
    }
    


    PFXHttpRequestWorker *worker = new PFXHttpRequestWorker(this, _manager);
    worker->setTimeOut(_timeOut);
    worker->setWorkingDirectory(_workingDirectory);
    PFXHttpRequestInput input(fullPath, "GET");

    foreach (QString key, this->defaultHeaders.keys()) { input.headers.insert(key, this->defaultHeaders.value(key)); }

    connect(worker, &PFXHttpRequestWorker::on_execution_finished, this, &PFXStoreApi::getInventoryCallback);
    connect(this, &PFXStoreApi::abortRequestsSignal, worker, &QObject::deleteLater); 
    worker->execute(&input);
}

void PFXStoreApi::getInventoryCallback(PFXHttpRequestWorker *worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    } else {
        msg = "Error: " + worker->error_str;
        error_str = QString("%1, %2").arg(worker->error_str).arg(QString(worker->response));
    }
    QMap<QString, qint32> output;
    QString json(worker->response);
    QByteArray array(json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject obj = doc.object();
    foreach (QString key, obj.keys()) {
        qint32 val;
        ::test_namespace::fromJsonValue(val, obj[key]);
        output.insert(key, val);
    }
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit getInventorySignal(output);
        emit getInventorySignalFull(worker, output);
    } else {
        emit getInventorySignalE(output, error_type, error_str);
        emit getInventorySignalEFull(worker, error_type, error_str);
    }
}

void PFXStoreApi::getOrderById(const qint64 &order_id) {
    QString fullPath = QString(_serverConfigs["getOrderById"][_serverIndices.value("getOrderById")].URL()+"/store/order/{orderId}");
    
    QString order_idPathParam("{");
    order_idPathParam.append("orderId").append("}");
    QString pathPrefix, pathSuffix, pathDelimiter;
    QString pathStyle = "";    
    if(pathStyle == "") 
        pathStyle = "simple";
    pathPrefix = getParamStylePrefix(pathStyle);
    pathSuffix = getParamStyleSuffix(pathStyle);
    pathDelimiter = getParamStyleDelimiter(pathStyle, "orderId", false);
    QString paramString = (pathStyle == "matrix") ? pathPrefix+"orderId"+pathSuffix : pathPrefix;
    fullPath.replace(order_idPathParam, paramString+QUrl::toPercentEncoding(::test_namespace::toStringValue(order_id)));


    PFXHttpRequestWorker *worker = new PFXHttpRequestWorker(this, _manager);
    worker->setTimeOut(_timeOut);
    worker->setWorkingDirectory(_workingDirectory);
    PFXHttpRequestInput input(fullPath, "GET");

    foreach (QString key, this->defaultHeaders.keys()) { input.headers.insert(key, this->defaultHeaders.value(key)); }

    connect(worker, &PFXHttpRequestWorker::on_execution_finished, this, &PFXStoreApi::getOrderByIdCallback);
    connect(this, &PFXStoreApi::abortRequestsSignal, worker, &QObject::deleteLater); 
    worker->execute(&input);
}

void PFXStoreApi::getOrderByIdCallback(PFXHttpRequestWorker *worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    } else {
        msg = "Error: " + worker->error_str;
        error_str = QString("%1, %2").arg(worker->error_str).arg(QString(worker->response));
    }
    PFXOrder output(QString(worker->response));
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit getOrderByIdSignal(output);
        emit getOrderByIdSignalFull(worker, output);
    } else {
        emit getOrderByIdSignalE(output, error_type, error_str);
        emit getOrderByIdSignalEFull(worker, error_type, error_str);
    }
}

void PFXStoreApi::placeOrder(const PFXOrder &body) {
    QString fullPath = QString(_serverConfigs["placeOrder"][_serverIndices.value("placeOrder")].URL()+"/store/order");
    


    PFXHttpRequestWorker *worker = new PFXHttpRequestWorker(this, _manager);
    worker->setTimeOut(_timeOut);
    worker->setWorkingDirectory(_workingDirectory);
    PFXHttpRequestInput input(fullPath, "POST");


    QString output = body.asJson();
    input.request_body.append(output.toUtf8());
    foreach (QString key, this->defaultHeaders.keys()) { input.headers.insert(key, this->defaultHeaders.value(key)); }

    connect(worker, &PFXHttpRequestWorker::on_execution_finished, this, &PFXStoreApi::placeOrderCallback);
    connect(this, &PFXStoreApi::abortRequestsSignal, worker, &QObject::deleteLater); 
    worker->execute(&input);
}

void PFXStoreApi::placeOrderCallback(PFXHttpRequestWorker *worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    } else {
        msg = "Error: " + worker->error_str;
        error_str = QString("%1, %2").arg(worker->error_str).arg(QString(worker->response));
    }
    PFXOrder output(QString(worker->response));
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit placeOrderSignal(output);
        emit placeOrderSignalFull(worker, output);
    } else {
        emit placeOrderSignalE(output, error_type, error_str);
        emit placeOrderSignalEFull(worker, error_type, error_str);
    }
}

} // namespace test_namespace
