var Name = prompt('Whats Your Name?');
if(Name == "" || Name == null || Name == undefined) {Name = prompt('Whats Your Name?');}

var socket = io();

var messages = document.getElementById('messages');
var form = document.getElementById('form');
var input = document.getElementById('input');
var ChatMessageName = 'chat-message-';

function AddTextToChatMessageName(Name) {
  ChatMessageName += Name;
}

form.addEventListener('submit', function(e) {
    if(Name == "" || Name == null || Name == undefined) {Name = prompt('Whats Your Name?');}
    e.preventDefault();
    if(input.value) {
        socket.emit(ChatMessageName, `${Name}: ${input.value}`);
        input.value = '';
    }
});

socket.on(ChatMessageName, function(msg) {
    console.log(msg);
    AddText(msg);
});

function AddText(msg) {
    var item = document.createElement('li');
    item.textContent = msg;
    messages.appendChild(item);
    window.scrollTo(0, document.body.scrollHeight);
}