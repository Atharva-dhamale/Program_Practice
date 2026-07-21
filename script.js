// ===============================
// Smooth Scroll
// ===============================

document.querySelectorAll('a[href^="#"]').forEach(anchor => {

    anchor.addEventListener("click", function(e){

        e.preventDefault();

        const target=document.querySelector(this.getAttribute("href"));

        if(target){

            target.scrollIntoView({

                behavior:"smooth"

            });

        }

    });

});


// ===============================
// Scroll Reveal
// ===============================

const observer=new IntersectionObserver((entries)=>{

    entries.forEach(entry=>{

        if(entry.isIntersecting){

            entry.target.style.opacity="1";

            entry.target.style.transform="translateY(0)";

        }

    });

},{threshold:0.2});

document.querySelectorAll(".wish-card,.quote-card,.memory-container,.celebration-card").forEach(item=>{

    item.style.opacity="0";

    item.style.transform="translateY(60px)";

    item.style.transition="1s";

    observer.observe(item);

});


// ===============================
// Hero Image Hover Animation
// ===============================

const image=document.querySelector(".image-card");

if(image){

image.addEventListener("mouseenter",()=>{

    image.style.transform="scale(1.05) rotate(2deg)";

});

image.addEventListener("mouseleave",()=>{

    image.style.transform="scale(1) rotate(0deg)";

});

}


// ===============================
// Floating Sparkles
// ===============================

function createSparkle(){

    const sparkle=document.createElement("div");

    sparkle.innerHTML="✨";

    sparkle.style.position="fixed";

    sparkle.style.left=Math.random()*window.innerWidth+"px";

    sparkle.style.top=window.innerHeight+"px";

    sparkle.style.fontSize=(Math.random()*15+10)+"px";

    sparkle.style.pointerEvents="none";

    sparkle.style.zIndex="999";

    document.body.appendChild(sparkle);

    let pos=window.innerHeight;

    const timer=setInterval(()=>{

        pos-=2;

        sparkle.style.top=pos+"px";

        sparkle.style.opacity=pos/window.innerHeight;

        if(pos<0){

            clearInterval(timer);

            sparkle.remove();

        }

    },20);

}

setInterval(createSparkle,500);


// ===============================
// Button Click Animation
// ===============================

document.querySelectorAll("button").forEach(btn=>{

    btn.addEventListener("click",()=>{

        btn.style.transform="scale(.9)";

        setTimeout(()=>{

            btn.style.transform="scale(1)";

        },150);

    });

});





// ===============================
// Simple Confetti
// ===============================

function confetti(){

    for(let i=0;i<120;i++){

        const piece=document.createElement("div");

        piece.style.position="fixed";

        piece.style.width="8px";

        piece.style.height="8px";

        piece.style.background=
        `hsl(${Math.random()*360},100%,60%)`;

        piece.style.left=Math.random()*window.innerWidth+"px";

        piece.style.top="-20px";

        piece.style.borderRadius="50%";

        piece.style.pointerEvents="none";

        piece.style.zIndex="9999";

        document.body.appendChild(piece);

        let y=-20;

        let x=parseFloat(piece.style.left);

        let speed=Math.random()*4+2;

        let rotate=Math.random()*360;

        const fall=setInterval(()=>{

            y+=speed;

            x+=Math.random()*2-1;

            rotate+=5;

            piece.style.top=y+"px";

            piece.style.left=x+"px";

            piece.style.transform=`rotate(${rotate}deg)`;

            if(y>window.innerHeight){

                clearInterval(fall);

                piece.remove();

            }

        },15);

    }

}

window.onload=()=>{

    confetti();

};


// ===============================
// Typing Effect
// ===============================

const title=document.querySelector(".hero-content h1");

if(title){

const text=title.innerHTML;

title.innerHTML="";

let i=0;

const typing=setInterval(()=>{

    title.innerHTML=text.substring(0,i);

    i++;

    if(i>text.length){

        clearInterval(typing);

    }

},60);

}

