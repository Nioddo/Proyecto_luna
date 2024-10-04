// Crear una escena, una cámara y un renderizador
const scene = new THREE.Scene();
const camera = new THREE.PerspectiveCamera(75, window.innerWidth / window.innerHeight, 0.1, 1000);
const renderer = new THREE.WebGLRenderer();
renderer.setSize(window.innerWidth, window.innerHeight);
document.body.appendChild(renderer.domElement);

// Crear la esfera de la Tierra
const geometry = new THREE.SphereGeometry(5, 32, 32);
const textureLoader = new THREE.TextureLoader();

// URL de la textura de la Tierra (asegúrate de usar una válida)
const earthTextureUrl = 'https://upload.wikimedia.org/wikipedia/commons/8/83/Earth_%28with_Atmosphere%29.jpg';

textureLoader.load(earthTextureUrl, (texture) => {
    const material = new THREE.MeshPhongMaterial({ map: texture });
    const earth = new THREE.Mesh(geometry, material);
    scene.add(earth);

    // Añadir luz
    const ambientLight = new THREE.AmbientLight(0x404040);
    scene.add(ambientLight);

    const directionalLight = new THREE.DirectionalLight(0xffffff, 1);
    directionalLight.position.set(5, 5, 5).normalize();
    scene.add(directionalLight);

    // Función de animación
    function animate() {
        requestAnimationFrame(animate);
        earth.rotation.y += 0.01; // Rotar la Tierra
        renderer.render(scene, camera);
    }

    // Iniciar la animación
    animate();
});

// Posicionar la cámara
camera.position.z = 10;

// Ajustar el tamaño del renderizador al cambiar el tamaño de la ventana
window.addEventListener('resize', () => {
    camera.aspect = window.innerWidth / window.innerHeight;
    camera.updateProjectionMatrix();
    renderer.setSize(window.innerWidth, window.innerHeight);
});
