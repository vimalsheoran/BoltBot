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
        alert("Please a valid API KEY and a Device ID");
    }
    else{
        alert("You are ready to play");
    }
}

function forward(){
    http.open("GET","https://cloud.boltiot.com/remote/"+apiKey+"/digitalWrite?pin=1&state=HIGH&deviceName="+deviceId,false);
    http.send();
    http.open("GET","https://cloud.boltiot.com/remote/"+apiKey+"/digitalWrite?pin=3&state=HIGH&deviceName="+deviceId,false);
    http.send();
    http.open("GET","https://cloud.boltiot.com/remote/"+apiKey+"/digitalWrite?pin=2&state=LOW&deviceName="+deviceId,false);
    http.send();
    http.open("GET","https://cloud.boltiot.com/remote/"+apiKey+"/digitalWrite?pin=4&state=LOW&deviceName="+deviceId,false);
    http.send();
}

function backward(){
    http.open("GET","https://cloud.boltiot.com/remote/"+apiKey+"/digitalWrite?pin=1&state=LOW&deviceName="+deviceId,false);
    http.open("GET","https://cloud.boltiot.com/remote/"+apiKey+"/digitalWrite?pin=3&state=LOW&deviceName="+deviceId,false);
    http.open("GET","https://cloud.boltiot.com/remote/"+apiKey+"/digitalWrite?pin=4&state=HIGH&deviceName="+deviceId,false);
    http.open("GET","https://cloud.boltiot.com/remote/"+apiKey+"/digitalWrite?pin=2&state=HIGH&deviceName="+deviceId,false);
    http.send();
}

function right(){
    http.open("GET","https://cloud.boltiot.com/remote/"+apiKey+"/digitalWrite?pin=1&state=HIGH&deviceName="+deviceId,false);
    http.open("GET","https://cloud.boltiot.com/remote/"+apiKey+"/digitalWrite?pin=2&state=LOW&deviceName="+deviceId,false);
    http.open("GET","https://cloud.boltiot.com/remote/"+apiKey+"/digitalWrite?pin=3&state=LOW&deviceName="+deviceId,false);
    http.open("GET","https://cloud.boltiot.com/remote/"+apiKey+"/digitalWrite?pin=4&state=LOW&deviceName="+deviceId,false);
    http.send();
}

function left(){
    http.open("GET","https://cloud.boltiot.com/remote/"+apiKey+"/digitalWrite?pin=1&state=LOW&deviceName="+deviceId,false);
    http.open("GET","https://cloud.boltiot.com/remote/"+apiKey+"/digitalWrite?pin=2&state=LOW&deviceName="+deviceId,false);
    http.open("GET","https://cloud.boltiot.com/remote/"+apiKey+"/digitalWrite?pin=3&state=HIGH&deviceName="+deviceId,false);
    http.open("GET","https://cloud.boltiot.com/remote/"+apiKey+"/digitalWrite?pin=4&state=LOW&deviceName="+deviceId,false);
    http.send();
}

