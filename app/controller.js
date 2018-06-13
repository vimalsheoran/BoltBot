var http = new XMLHttpRequest();

var apiKey, deviceId;

$(".form-inline").submit(function(){
    getCredentials();
    return false;
});

function getCredentials(){
    apiKey = document.forms["credentialsForm"]["apiKey"].value;
    deviceId = document.forms["credentialsForm"]["deviceId"].value;
    if(apiKey == "" || deviceId == ""){
        alert("Please enter an API KEY and a Device ID");
    }
    else{
        alert("You are ready to play");
    }
}

function forward(){
    http.open("GET","https://cloud.boltiot.com/remote/"+apiKey+"/serialWrite?data=FORWARD&deviceName="+deviceId,false);
    http.send();

}

function backward(){
    http.open("GET","https://cloud.boltiot.com/remote/"+apiKey+"/serialWrite?data=BACKWARD&deviceName="+deviceId,false);
    http.send();
}

function right(){
    http.open("GET","https://cloud.boltiot.com/remote/"+apiKey+"/serialWrite?data=RIGHT&deviceName="+deviceId,false);
    http.send();
}

function left(){
    http.open("GET","https://cloud.boltiot.com/remote/"+apiKey+"/serialWrite?data=LEFT&deviceName="+deviceId,false);
    http.send();
}

function stop(){
    http.open("GET","https://cloud.boltiot.com/remote/"+apiKey+"/serialWrite?data=STOP&deviceName="+deviceId,false);
    http.send();
}
