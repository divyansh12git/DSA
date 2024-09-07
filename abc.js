const a=document.getElementById("tt");
const but=document.getElementsByClassName("prakash")[0];
const area=document.querySelector('#area');
const y=document.querySelector('#shakti');
console.log(a.innerHTML);
a.style.color="red";
function doSomething(e){
    const msg=y.value
    const x=document.createElement("p");
    x.innerHTML=`${msg}`;
    y.value="";
    console.log("HI");
    area.appendChild(x);
    area.scrollTo(0, area.scrollHeight);

}
but.addEventListener("click",doSomething);
y.addEventListener("keypress",(event)=>{
    if (event.key === "Enter") {
        console.log("hi");
        event.preventDefault();
        doSomething(event);
      }
});
