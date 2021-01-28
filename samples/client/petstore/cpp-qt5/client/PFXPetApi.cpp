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

#include "PFXPetApi.h"
#include "PFXHelpers.h"
#include "PFXServerConfiguration.h"
#include <QJsonArray>
#include <QJsonDocument>

namespace test_namespace {

PFXPetApi::PFXPetApi(const QString &scheme, const QString &host, int port, const QString &basePath, const int timeOut)
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

PFXPetApi::~PFXPetApi() {
}

void PFXPetApi::initializeServerConfigs(){

//Default server
QList<PFXServerConfiguration> defaultConf = QList<PFXServerConfiguration>();
//varying endpoint server 
QList<PFXServerConfiguration> serverConf = QList<PFXServerConfiguration>();
defaultConf.append(PFXServerConfiguration(
    "http://petstore.swagger.io/v2",
    "No description provided",
    QMap<QString, PFXServerVariable>()));
_serverConfigs.insert("addPet",defaultConf);
_serverIndices.insert("addPet",0);

_serverConfigs.insert("deletePet",defaultConf);
_serverIndices.insert("deletePet",0);

_serverConfigs.insert("findPetsByStatus",defaultConf);
_serverIndices.insert("findPetsByStatus",0);

_serverConfigs.insert("findPetsByTags",defaultConf);
_serverIndices.insert("findPetsByTags",0);

_serverConfigs.insert("getPetById",defaultConf);
_serverIndices.insert("getPetById",0);

_serverConfigs.insert("updatePet",defaultConf);
_serverIndices.insert("updatePet",0);

_serverConfigs.insert("updatePetWithForm",defaultConf);
_serverIndices.insert("updatePetWithForm",0);

_serverConfigs.insert("uploadFile",defaultConf);
_serverIndices.insert("uploadFile",0);


}

/**
* returns 0 on success and -1, -2 or -3 on failure.
* -1 when the variable does not exist and -2 if the value is not defined in the enum and -3 if the operation or server index is not found 
*/
int PFXPetApi::setDefaultServerValue(int serverIndex, const QString &operation, const QString &variable, const QString &value){
    auto it = _serverConfigs.find(operation);
    if(it != _serverConfigs.end() && serverIndex < it.value().size() ){
      return _serverConfigs[operation][serverIndex].setDefaultValue(variable,value);
    }
    return -3;
}
void PFXPetApi::setServerIndex(const QString &operation, int serverIndex){
    if(_serverIndices.contains(operation) && serverIndex < _serverConfigs.find(operation).value().size() )
        _serverIndices[operation] = serverIndex;
}

void PFXPetApi::setScheme(const QString &scheme) {
    _scheme = scheme;
}

void PFXPetApi::setHost(const QString &host) {
    _host = host;
}

void PFXPetApi::setPort(int port) {
    _port = port;
}

void PFXPetApi::setApiKey(const QString &apiKeyName, const QString &apiKey){
    _apiKeys.insert(apiKeyName,apiKey);
}

void PFXPetApi::setBearerToken(const QString &token){
    _bearerToken = token;
}

void PFXPetApi::setUsername(const QString &username) {
    _username = username;
}

void PFXPetApi::setPassword(const QString &password) {
    _password = password;
}

void PFXPetApi::setBasePath(const QString &basePath) {
    _basePath = basePath;
}

void PFXPetApi::setTimeOut(const int timeOut) {
    _timeOut = timeOut;
}

void PFXPetApi::setWorkingDirectory(const QString &path) {
    _workingDirectory = path;
}

void PFXPetApi::setNetworkAccessManager(QNetworkAccessManager* manager) {
    _manager = manager;  
}

void PFXPetApi::addHeaders(const QString &key, const QString &value) {
    defaultHeaders.insert(key, value);
}

void PFXPetApi::enableRequestCompression() {
    isRequestCompressionEnabled = true;
}

void PFXPetApi::enableResponseCompression() {
    isResponseCompressionEnabled = true;
}

void PFXPetApi::abortRequests(){
    emit abortRequestsSignal();
}

QString PFXPetApi::getParamStylePrefix(QString style){

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

QString PFXPetApi::getParamStyleSuffix(QString style){

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

QString PFXPetApi::getParamStyleDelimiter(QString style, QString name, bool isExplode){

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

void PFXPetApi::addPet(const PFXPet &body) {
    QString fullPath = QString(_serverConfigs["addPet"][_serverIndices.value("addPet")].URL()+"/pet");



    PFXHttpRequestWorker *worker = new PFXHttpRequestWorker(this, _manager);
    worker->setTimeOut(_timeOut);
    worker->setWorkingDirectory(_workingDirectory);
    PFXHttpRequestInput input(fullPath, "POST");


    QString output = body.asJson();
    input.request_body.append(output.toUtf8());
    foreach (QString key, this->defaultHeaders.keys()) { input.headers.insert(key, this->defaultHeaders.value(key)); }

    connect(worker, &PFXHttpRequestWorker::on_execution_finished, this, &PFXPetApi::addPetCallback);
    connect(this, &PFXPetApi::abortRequestsSignal, worker, &QObject::deleteLater); 
    worker->execute(&input);
}

void PFXPetApi::addPetCallback(PFXHttpRequestWorker *worker) {
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
        emit addPetSignal();
        emit addPetSignalFull(worker);
    } else {
        emit addPetSignalE(error_type, error_str);
        emit addPetSignalEFull(worker, error_type, error_str);
    }
}

void PFXPetApi::deletePet(const qint64 &pet_id, const QString &api_key) {
    QString fullPath = QString(_serverConfigs["deletePet"][_serverIndices.value("deletePet")].URL()+"/pet/{petId}");

    QString pet_idPathParam("{");
    pet_idPathParam.append("petId").append("}");
    QString pathPrefix, pathSuffix, pathDelimiter;
    QString pathStyle = "";    
    if(pathStyle == "") 
        pathStyle = "simple";
    pathPrefix = getParamStylePrefix(pathStyle);
    pathSuffix = getParamStyleSuffix(pathStyle);
    pathDelimiter = getParamStyleDelimiter(pathStyle, "petId", false);
    QString paramString = (pathStyle == "matrix") ? pathPrefix+"petId"+pathSuffix : pathPrefix;
    fullPath.replace(pet_idPathParam, paramString+QUrl::toPercentEncoding(::test_namespace::toStringValue(pet_id)));


    PFXHttpRequestWorker *worker = new PFXHttpRequestWorker(this, _manager);
    worker->setTimeOut(_timeOut);
    worker->setWorkingDirectory(_workingDirectory);
    PFXHttpRequestInput input(fullPath, "DELETE");



    if (!::test_namespace::toStringValue(api_key).isEmpty()) {
        input.headers.insert("api_key", ::test_namespace::toStringValue(api_key));
    }
    foreach (QString key, this->defaultHeaders.keys()) { input.headers.insert(key, this->defaultHeaders.value(key)); }

    connect(worker, &PFXHttpRequestWorker::on_execution_finished, this, &PFXPetApi::deletePetCallback);
    connect(this, &PFXPetApi::abortRequestsSignal, worker, &QObject::deleteLater); 
    worker->execute(&input);
}

void PFXPetApi::deletePetCallback(PFXHttpRequestWorker *worker) {
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
        emit deletePetSignal();
        emit deletePetSignalFull(worker);
    } else {
        emit deletePetSignalE(error_type, error_str);
        emit deletePetSignalEFull(worker, error_type, error_str);
    }
}

void PFXPetApi::findPetsByStatus(const QList<QString> &status) {
    QString fullPath = QString(_serverConfigs["findPetsByStatus"][_serverIndices.value("findPetsByStatus")].URL()+"/pet/findByStatus");


    QString queryPrefix, querySuffix, queryDelimiter, queryStyle;
    queryStyle = "form";
    if(queryStyle == "") 
        queryStyle = "form";
    queryPrefix = getParamStylePrefix(queryStyle);
    querySuffix = getParamStyleSuffix(queryStyle);
    queryDelimiter = getParamStyleDelimiter(queryStyle, "status", false); 

    if (status.size() > 0) {
        if (QString("csv").indexOf("multi") == 0) {
            foreach (QString t, status) {
                if (fullPath.indexOf("?") > 0)
                    fullPath.append(queryPrefix);
                else
                    fullPath.append("?");
                fullPath.append("status=").append(::test_namespace::toStringValue(t));
            }
        } else if (QString("csv").indexOf("ssv") == 0) {
            if (fullPath.indexOf("?") > 0)
                fullPath.append("&");
            else
                fullPath.append("?").append(queryPrefix).append("status").append(querySuffix);
            qint32 count = 0;
            foreach (QString t, status) {
                if (count > 0) {
                    fullPath.append((false)? queryDelimiter : QUrl::toPercentEncoding(queryDelimiter));
                }
                fullPath.append(::test_namespace::toStringValue(t));
                count++;
            }
        } else if (QString("csv").indexOf("tsv") == 0) {
            if (fullPath.indexOf("?") > 0)
                fullPath.append("&");
            else
                fullPath.append("?").append(queryPrefix).append("status").append(querySuffix);
            qint32 count = 0;
            foreach (QString t, status) {
                if (count > 0) {
                    fullPath.append("\t");
                }
                fullPath.append(::test_namespace::toStringValue(t));
                count++;
            }
        } else if (QString("csv").indexOf("csv") == 0) {
            if (fullPath.indexOf("?") > 0)
                fullPath.append("&");
            else
                fullPath.append("?").append(queryPrefix).append("status").append(querySuffix);
            qint32 count = 0;
            foreach (QString t, status) {
                if (count > 0) {
                    fullPath.append(queryDelimiter);
                }
                fullPath.append(::test_namespace::toStringValue(t));
                count++;
            }
        } else if (QString("csv").indexOf("pipes") == 0) {
            if (fullPath.indexOf("?") > 0)
                fullPath.append("&");
            else
                fullPath.append("?").append(queryPrefix).append("status").append(querySuffix);
            qint32 count = 0;
            foreach (QString t, status) {
                if (count > 0) {
                    fullPath.append(queryDelimiter);
                }
                fullPath.append(::test_namespace::toStringValue(t));
                count++;
            }
        } else if (QString("csv").indexOf("deepObject") == 0) {
            if (fullPath.indexOf("?") > 0)
                fullPath.append("&");
            else
                fullPath.append("?").append(queryPrefix).append("status").append(querySuffix);
            qint32 count = 0;
            foreach (QString t, status) {
                if (count > 0) {
                    fullPath.append(queryDelimiter);
                }
                fullPath.append(::test_namespace::toStringValue(t));
                count++;
            }   
        }
    }

    PFXHttpRequestWorker *worker = new PFXHttpRequestWorker(this, _manager);
    worker->setTimeOut(_timeOut);
    worker->setWorkingDirectory(_workingDirectory);
    PFXHttpRequestInput input(fullPath, "GET");

    foreach (QString key, this->defaultHeaders.keys()) { input.headers.insert(key, this->defaultHeaders.value(key)); }

    connect(worker, &PFXHttpRequestWorker::on_execution_finished, this, &PFXPetApi::findPetsByStatusCallback);
    connect(this, &PFXPetApi::abortRequestsSignal, worker, &QObject::deleteLater); 
    worker->execute(&input);
}

void PFXPetApi::findPetsByStatusCallback(PFXHttpRequestWorker *worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    } else {
        msg = "Error: " + worker->error_str;
        error_str = QString("%1, %2").arg(worker->error_str).arg(QString(worker->response));
    }
    QList<PFXPet> output;
    QString json(worker->response);
    QByteArray array(json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonArray jsonArray = doc.array();
    foreach (QJsonValue obj, jsonArray) {
        PFXPet val;
        ::test_namespace::fromJsonValue(val, obj);
        output.append(val);
    }
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit findPetsByStatusSignal(output);
        emit findPetsByStatusSignalFull(worker, output);
    } else {
        emit findPetsByStatusSignalE(output, error_type, error_str);
        emit findPetsByStatusSignalEFull(worker, error_type, error_str);
    }
}

void PFXPetApi::findPetsByTags(const QList<QString> &tags) {
    QString fullPath = QString(_serverConfigs["findPetsByTags"][_serverIndices.value("findPetsByTags")].URL()+"/pet/findByTags");


    QString queryPrefix, querySuffix, queryDelimiter, queryStyle;
    queryStyle = "form";
    if(queryStyle == "") 
        queryStyle = "form";
    queryPrefix = getParamStylePrefix(queryStyle);
    querySuffix = getParamStyleSuffix(queryStyle);
    queryDelimiter = getParamStyleDelimiter(queryStyle, "tags", false); 

    if (tags.size() > 0) {
        if (QString("csv").indexOf("multi") == 0) {
            foreach (QString t, tags) {
                if (fullPath.indexOf("?") > 0)
                    fullPath.append(queryPrefix);
                else
                    fullPath.append("?");
                fullPath.append("tags=").append(::test_namespace::toStringValue(t));
            }
        } else if (QString("csv").indexOf("ssv") == 0) {
            if (fullPath.indexOf("?") > 0)
                fullPath.append("&");
            else
                fullPath.append("?").append(queryPrefix).append("tags").append(querySuffix);
            qint32 count = 0;
            foreach (QString t, tags) {
                if (count > 0) {
                    fullPath.append((false)? queryDelimiter : QUrl::toPercentEncoding(queryDelimiter));
                }
                fullPath.append(::test_namespace::toStringValue(t));
                count++;
            }
        } else if (QString("csv").indexOf("tsv") == 0) {
            if (fullPath.indexOf("?") > 0)
                fullPath.append("&");
            else
                fullPath.append("?").append(queryPrefix).append("tags").append(querySuffix);
            qint32 count = 0;
            foreach (QString t, tags) {
                if (count > 0) {
                    fullPath.append("\t");
                }
                fullPath.append(::test_namespace::toStringValue(t));
                count++;
            }
        } else if (QString("csv").indexOf("csv") == 0) {
            if (fullPath.indexOf("?") > 0)
                fullPath.append("&");
            else
                fullPath.append("?").append(queryPrefix).append("tags").append(querySuffix);
            qint32 count = 0;
            foreach (QString t, tags) {
                if (count > 0) {
                    fullPath.append(queryDelimiter);
                }
                fullPath.append(::test_namespace::toStringValue(t));
                count++;
            }
        } else if (QString("csv").indexOf("pipes") == 0) {
            if (fullPath.indexOf("?") > 0)
                fullPath.append("&");
            else
                fullPath.append("?").append(queryPrefix).append("tags").append(querySuffix);
            qint32 count = 0;
            foreach (QString t, tags) {
                if (count > 0) {
                    fullPath.append(queryDelimiter);
                }
                fullPath.append(::test_namespace::toStringValue(t));
                count++;
            }
        } else if (QString("csv").indexOf("deepObject") == 0) {
            if (fullPath.indexOf("?") > 0)
                fullPath.append("&");
            else
                fullPath.append("?").append(queryPrefix).append("tags").append(querySuffix);
            qint32 count = 0;
            foreach (QString t, tags) {
                if (count > 0) {
                    fullPath.append(queryDelimiter);
                }
                fullPath.append(::test_namespace::toStringValue(t));
                count++;
            }   
        }
    }

    PFXHttpRequestWorker *worker = new PFXHttpRequestWorker(this, _manager);
    worker->setTimeOut(_timeOut);
    worker->setWorkingDirectory(_workingDirectory);
    PFXHttpRequestInput input(fullPath, "GET");

    foreach (QString key, this->defaultHeaders.keys()) { input.headers.insert(key, this->defaultHeaders.value(key)); }

    connect(worker, &PFXHttpRequestWorker::on_execution_finished, this, &PFXPetApi::findPetsByTagsCallback);
    connect(this, &PFXPetApi::abortRequestsSignal, worker, &QObject::deleteLater); 
    worker->execute(&input);
}

void PFXPetApi::findPetsByTagsCallback(PFXHttpRequestWorker *worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    } else {
        msg = "Error: " + worker->error_str;
        error_str = QString("%1, %2").arg(worker->error_str).arg(QString(worker->response));
    }
    QList<PFXPet> output;
    QString json(worker->response);
    QByteArray array(json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonArray jsonArray = doc.array();
    foreach (QJsonValue obj, jsonArray) {
        PFXPet val;
        ::test_namespace::fromJsonValue(val, obj);
        output.append(val);
    }
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit findPetsByTagsSignal(output);
        emit findPetsByTagsSignalFull(worker, output);
    } else {
        emit findPetsByTagsSignalE(output, error_type, error_str);
        emit findPetsByTagsSignalEFull(worker, error_type, error_str);
    }
}

void PFXPetApi::getPetById(const qint64 &pet_id) {
    QString fullPath = QString(_serverConfigs["getPetById"][_serverIndices.value("getPetById")].URL()+"/pet/{petId}");
        }else if(style == "deepObject"){
            return (isExplode) ? "&" + name + "=" : "|";
    
    QString pet_idPathParam("{");
    pet_idPathParam.append("petId").append("}");
    QString pathPrefix, pathSuffix, pathDelimiter;
    QString pathStyle = "";    
    if(pathStyle == "") 
        pathStyle = "simple";
    pathPrefix = getParamStylePrefix(pathStyle);
    pathSuffix = getParamStyleSuffix(pathStyle);
    pathDelimiter = getParamStyleDelimiter(pathStyle, "petId", false);
    QString paramString = (pathStyle == "matrix") ? pathPrefix+"petId"+pathSuffix : pathPrefix;
    fullPath.replace(pet_idPathParam, paramString+QUrl::toPercentEncoding(::test_namespace::toStringValue(pet_id)));


    PFXHttpRequestWorker *worker = new PFXHttpRequestWorker(this, _manager);
    worker->setTimeOut(_timeOut);
    worker->setWorkingDirectory(_workingDirectory);
    PFXHttpRequestInput input(fullPath, "GET");

    foreach (QString key, this->defaultHeaders.keys()) { input.headers.insert(key, this->defaultHeaders.value(key)); }

    connect(worker, &PFXHttpRequestWorker::on_execution_finished, this, &PFXPetApi::getPetByIdCallback);
    connect(this, &PFXPetApi::abortRequestsSignal, worker, &QObject::deleteLater); 
    worker->execute(&input);
}

void PFXPetApi::getPetByIdCallback(PFXHttpRequestWorker *worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    } else {
        msg = "Error: " + worker->error_str;
        error_str = QString("%1, %2").arg(worker->error_str).arg(QString(worker->response));
    }
    PFXPet output(QString(worker->response));
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit getPetByIdSignal(output);
        emit getPetByIdSignalFull(worker, output);
    } else {
        emit getPetByIdSignalE(output, error_type, error_str);
        emit getPetByIdSignalEFull(worker, error_type, error_str);
    }
}

void PFXPetApi::updatePet(const PFXPet &body) {
    QString fullPath = QString(_serverConfigs["updatePet"][_serverIndices.value("updatePet")].URL()+"/pet");



    PFXHttpRequestWorker *worker = new PFXHttpRequestWorker(this, _manager);
    worker->setTimeOut(_timeOut);
    worker->setWorkingDirectory(_workingDirectory);
    PFXHttpRequestInput input(fullPath, "PUT");

  
    QString output = body.asJson();
    input.request_body.append(output.toUtf8());
    foreach (QString key, this->defaultHeaders.keys()) { input.headers.insert(key, this->defaultHeaders.value(key)); }

    connect(worker, &PFXHttpRequestWorker::on_execution_finished, this, &PFXPetApi::updatePetCallback);
    connect(this, &PFXPetApi::abortRequestsSignal, worker, &QObject::deleteLater); 
    worker->execute(&input);
}

void PFXPetApi::updatePetCallback(PFXHttpRequestWorker *worker) {
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
        emit updatePetSignal();
        emit updatePetSignalFull(worker);
    } else {
        emit updatePetSignalE(error_type, error_str);
        emit updatePetSignalEFull(worker, error_type, error_str);
    }
}

void PFXPetApi::updatePetWithForm(const qint64 &pet_id, const QString &name, const QString &status) {
    QString fullPath = QString(_serverConfigs["updatePetWithForm"][_serverIndices.value("updatePetWithForm")].URL()+"/pet/{petId}");

    QString pet_idPathParam("{");
    pet_idPathParam.append("petId").append("}");
    QString pathPrefix, pathSuffix, pathDelimiter;
    QString pathStyle = "";    
    if(pathStyle == "") 
        pathStyle = "simple";
    pathPrefix = getParamStylePrefix(pathStyle);
    pathSuffix = getParamStyleSuffix(pathStyle);
    pathDelimiter = getParamStyleDelimiter(pathStyle, "petId", false);
    QString paramString = (pathStyle == "matrix") ? pathPrefix+"petId"+pathSuffix : pathPrefix;
    fullPath.replace(pet_idPathParam, paramString+QUrl::toPercentEncoding(::test_namespace::toStringValue(pet_id)));


    PFXHttpRequestWorker *worker = new PFXHttpRequestWorker(this, _manager);
    worker->setTimeOut(_timeOut);
    worker->setWorkingDirectory(_workingDirectory);
    PFXHttpRequestInput input(fullPath, "POST");

    input.add_var("name", ::test_namespace::toStringValue(name));    input.add_var("status", ::test_namespace::toStringValue(status));    foreach (QString key, this->defaultHeaders.keys()) { input.headers.insert(key, this->defaultHeaders.value(key)); }

    connect(worker, &PFXHttpRequestWorker::on_execution_finished, this, &PFXPetApi::updatePetWithFormCallback);
    connect(this, &PFXPetApi::abortRequestsSignal, worker, &QObject::deleteLater); 
    worker->execute(&input);
}

void PFXPetApi::updatePetWithFormCallback(PFXHttpRequestWorker *worker) {
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
        emit updatePetWithFormSignal();
        emit updatePetWithFormSignalFull(worker);
    } else {
        emit updatePetWithFormSignalE(error_type, error_str);
        emit updatePetWithFormSignalEFull(worker, error_type, error_str);
    }
}

void PFXPetApi::uploadFile(const qint64 &pet_id, const QString &additional_metadata, const PFXHttpFileElement &file) {
    QString fullPath = QString(_serverConfigs["uploadFile"][_serverIndices.value("uploadFile")].URL()+"/pet/{petId}/uploadImage");

    QString pet_idPathParam("{");
    pet_idPathParam.append("petId").append("}");
    QString pathPrefix, pathSuffix, pathDelimiter;
    QString pathStyle = "";    
    if(pathStyle == "") 
        pathStyle = "simple";
    pathPrefix = getParamStylePrefix(pathStyle);
    pathSuffix = getParamStyleSuffix(pathStyle);
    pathDelimiter = getParamStyleDelimiter(pathStyle, "petId", false);
    QString paramString = (pathStyle == "matrix") ? pathPrefix+"petId"+pathSuffix : pathPrefix;
    fullPath.replace(pet_idPathParam, paramString+QUrl::toPercentEncoding(::test_namespace::toStringValue(pet_id)));


    PFXHttpRequestWorker *worker = new PFXHttpRequestWorker(this, _manager);
    worker->setTimeOut(_timeOut);
    worker->setWorkingDirectory(_workingDirectory);
    PFXHttpRequestInput input(fullPath, "POST");

    input.add_var("additionalMetadata", ::test_namespace::toStringValue(additional_metadata));
    input.add_file("file", file.local_filename, file.request_filename, file.mime_type);    foreach (QString key, this->defaultHeaders.keys()) { input.headers.insert(key, this->defaultHeaders.value(key)); }

    connect(worker, &PFXHttpRequestWorker::on_execution_finished, this, &PFXPetApi::uploadFileCallback);
    connect(this, &PFXPetApi::abortRequestsSignal, worker, &QObject::deleteLater); 
    worker->execute(&input);
}

void PFXPetApi::uploadFileCallback(PFXHttpRequestWorker *worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    } else {
        msg = "Error: " + worker->error_str;
        error_str = QString("%1, %2").arg(worker->error_str).arg(QString(worker->response));
    }
    PFXApiResponse output(QString(worker->response));
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit uploadFileSignal(output);
        emit uploadFileSignalFull(worker, output);
    } else {
        emit uploadFileSignalE(output, error_type, error_str);
        emit uploadFileSignalEFull(worker, error_type, error_str);
    }
}

} // namespace test_namespace
