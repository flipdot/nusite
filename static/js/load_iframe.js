window.flipdot = window.flipdot || {};
window.flipdot.loadIframe = (event, elemId, iframeSrc) => {
    event.preventDefault();
    event.target.classList.add("hidden");

    const elem = document.getElementById(elemId);
    elem.src = iframeSrc;
    elem.classList.remove("hidden");
};
