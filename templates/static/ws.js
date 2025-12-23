let socket = new WebSocket("ws://localhost:18080/ws");

socket.onopen = function() {
  alert("[open] Connection established");
  alert("Sending to server");
  socket.send("testing connection");
};

socket.onmessage = function(event) {
  alert(`[message] Data received from server: ${event.data}`);
};

socket.onclose = function(event) {
  if (event.wasClean) {
    alert(`[close] Connection closed cleanly, code=${event.code} reason=${event.reason}`);
    alert('[close] Connection died');
  }
};

socket.onerror = function(error) {
  alert(`[error]`);
};

// debounce
let debounceTime;
// initialise/ set the timer
function startTimer() {
    debounceTime = setTimeout(timerChoice(), 500);
}
// listen for each change in the form called code
const input = document.getElementById('code-form');
/**
 * function timerChoice() {
    // re start the timer if there is an update
    if () {
        startTimer();
    }
}

function sendToServer() {

}
*/