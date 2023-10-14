javascript: (() => {
    var id = prompt("Enter the ID:");
    var newDiv = document.createElement("div");
    newDiv.id = id;
    newDiv.textContent = "This is a new div element with the ID '" + id + "'.";
    document.body.appendChild(newDiv);
})();




javascript:(function(){
    var Site = document.createElement("iframe");
    Site.src = "artclass.site";
    Site.width = "100%";
    Site.height = "100%";
    document.body.appendChild(Site);
})();