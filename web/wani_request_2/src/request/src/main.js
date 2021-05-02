import Vue from 'vue'
import { BootstrapVue, BootstrapVueIcons } from 'bootstrap-vue'
import app from './App.vue'
import router from './router'

Vue.config.productionTip = false

Vue.use(BootstrapVue)
Vue.use(BootstrapVueIcons)

import 'bootstrap/dist/css/bootstrap.css'
import 'bootstrap-vue/dist/bootstrap-vue.css'

new Vue({
  router,
  render: h => h(app),
}).$mount('#app')
