let c_ordenar, c_get_tam, c_get_livro_titulo, c_get_livro_preco;

// Aguarda a inicialização do Módulo WebAssembly
Module['onRuntimeInitialized'] = function() {
    // Mapeia as funções C para chamadas JS
    c_ordenar = Module.cwrap('ordenar', null, ['number']);
    c_get_tam = Module.cwrap('get_tam', 'number', []);
    c_get_livro_titulo = Module.cwrap('get_livro_titulo', 'string', ['number']);
    c_get_livro_preco = Module.cwrap('get_livro_preco', 'number', ['number']);

    // Aplica a ordenação padrão ao carregar
    aplicarOrdenacao();
};

function renderizarTabela() {
    const tbody = document.getElementById('corpo-tabela');
    tbody.innerHTML = '';

    const tam = c_get_tam();

    for (let i = 0; i < tam; i++) {
        const titulo = c_get_livro_titulo(i);
        const preco = c_get_livro_preco(i);

        const tr = document.createElement('tr');
        tr.innerHTML = `
