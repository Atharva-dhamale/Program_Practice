
// ======================================
// MOBILE NAVIGATION
// ======================================

const menuButton = document.querySelector(".menu-toggle");
const navigation = document.querySelector(".nav-links");

if (menuButton && navigation) {

    menuButton.addEventListener("click", () => {

        const isOpen = navigation.classList.toggle("open");

        menuButton.setAttribute(
            "aria-expanded",
            String(isOpen)
        );

    });

}


// ======================================
// BACKGROUND MUSIC
// ======================================

const music = document.getElementById("bgMusic");
const musicButton = document.querySelector(".music-toggle");

if (music && musicButton) {

    musicButton.addEventListener("click", async () => {

        try {

            if (music.paused) {

                await music.play();

                musicButton.classList.add("is-playing");

                musicButton.querySelector(".music-label").textContent =
                    "Pause music";

            } else {

                music.pause();

                musicButton.classList.remove("is-playing");

                musicButton.querySelector(".music-label").textContent =
                    "Play music";

            }

        } catch (error) {

            console.log("Music could not be played:", error);

        }

    });

}


// ======================================
// IMAGE GALLERY LIGHTBOX
// ======================================

const lightbox = document.querySelector(".lightbox");

if (lightbox) {

    const lightboxImage = lightbox.querySelector("img");

    const closeButton =
        lightbox.querySelector(".lightbox-close");


    document.querySelectorAll(".gallery-item").forEach(item => {

        item.addEventListener("click", () => {

            const image = item.querySelector("img");

            lightboxImage.src =
                item.dataset.full || image.src;

            lightboxImage.alt = image.alt;

            lightbox.classList.add("open");

            document.body.style.overflow = "hidden";

        });

    });


    function closeLightbox() {

        lightbox.classList.remove("open");

        document.body.style.overflow = "";

    }


    closeButton.addEventListener("click", closeLightbox);


    lightbox.addEventListener("click", event => {

        if (event.target === lightbox) {

            closeLightbox();

        }

    });


    document.addEventListener("keydown", event => {

        if (event.key === "Escape") {

            closeLightbox();

        }

    });

}


// ======================================
// BIRTHDAY GIFT REVEAL
// ======================================

const surpriseStage =
    document.querySelector(".surprise-stage");


if (surpriseStage) {

    const giftButton =
        surpriseStage.querySelector(".gift-button");

    const celebrateButton =
        surpriseStage.querySelector(".celebrate-btn");


    giftButton.addEventListener("click", () => {

        surpriseStage.classList.add("opened");

        launchConfetti(150);

    });


    celebrateButton.addEventListener("click", () => {

        launchConfetti(110);

    });

}


// ======================================
// CONFETTI ANIMATION
// ======================================

function launchConfetti(amount = 100) {

    const layer =
        document.querySelector(".confetti-layer") ||
        createConfettiLayer();

    const colors = [
        "#f3cc91",
        "#ed9bb8",
        "#b89be7",
        "#fff2df",
        "#d987a8"
    ];


    for (let i = 0; i < amount; i++) {

        const piece = document.createElement("span");

        piece.className = "confetti-piece";

        piece.style.left =
            Math.random() * 100 + "%";

        piece.style.background =
            colors[Math.floor(Math.random() * colors.length)];

        piece.style.animationDelay =
            Math.random() * 0.8 + "s";

        piece.style.animationDuration =
            2.2 + Math.random() * 1.8 + "s";

        piece.style.setProperty(
            "--drift",
            (Math.random() * 220 - 110) + "px"
        );

        piece.style.borderRadius =
            Math.random() > 0.5 ? "50%" : "2px";

        layer.appendChild(piece);


        piece.addEventListener("animationend", () => {

            piece.remove();

        });

    }

}


// ======================================
// CREATE CONFETTI CONTAINER
// ======================================

function createConfettiLayer() {

    const layer = document.createElement("div");

    layer.className = "confetti-layer";

    layer.setAttribute("aria-hidden", "true");

    document.body.appendChild(layer);

    return layer;

}
