import Vue from "vue";
import Router from "vue-router";
import index from '@/pages/Index.vue';
import page1 from '@/pages/Page1.vue';
import page2 from '@/pages/Page2.vue';
Vue.use(Router);

export default new Router({
    mode: "history",
    routes: [
        {
            path: '/',
            component: index,
            name: 'index',
        },
        {
            path: '/page1',
            component: page1,
            name: 'page1',
        },
        {
            path: '/page2',
            component: page2,
            name: 'page2',
        },
    ]
})