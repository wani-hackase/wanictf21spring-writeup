module.exports = {
    devServer: {
        watchOptions: {
            poll: true
        },
        proxy: 'http://localhost:3000/'
    },
}
