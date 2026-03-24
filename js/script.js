// MathJax
(function() {
    const mathjaxURL = "https://cdn.jsdelivr.net/npm/mathjax@4.0.0/tex-mml-chtml.js";

    if (!document.getElementById("MathJax-script")) {
        const script = document.createElement("script");
        script.id = "MathJax-script";
        script.async = true;
        script.src = mathjaxURL;

        document.head.appendChild(script);
    }
})();

// Drive pdf
document.addEventListener("DOMContentLoaded", function() {
    document.querySelectorAll("iframe.d").forEach(iframe => {
        //const id = iframe.textContent.trim();
        const id = iframe.dataset.id;
        //iframe.textContent = "";
        iframe.src = `https://drive.google.com/file/d/${id}/preview`;
        iframe.setAttribute("allow", "autoplay");
    });
});
