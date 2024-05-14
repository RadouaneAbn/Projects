const addBtn = document.getElementById('add-btn');
const listHolder = document.getElementById('list-holder');


const textHolder = `
    <div class="item">
        <img class="dlt-icon" src="icons/x.png" alt="" width="20px" height="20px">

        <input type="text" class="input-text" placeholder="Enter a text" value="">
        <img class="cpy-icon" src="icons/copy.png" alt="" width="20px" height="20px">
    </div>
`

addBtn.addEventListener('click', function () {
    // $('ul#list-holder').append(textHolder)
    const tmpCon = document.createElement('li');
    tmpCon.innerHTML = textHolder;
    listHolder.appendChild(tmpCon);
    reloadDeleteBtns();
    reloadCopyBtns();
})

function reloadCopyBtns() {
    const allCopyBtns = document.querySelectorAll('img.cpy-icon');
    allCopyBtns.forEach(btn => {
        btn.addEventListener('click', function() {
            const val = this.parentNode.querySelector('.input-text');
            console.log(val.value)
        })
    })
}


function reloadDeleteBtns() {
    const allDeleteBtns = document.querySelectorAll('img.dlt-icon');
    allDeleteBtns.forEach(btn => {
        btn.addEventListener('click', function() {
            this.parentNode.parentNode.remove();
        })
    })
}

