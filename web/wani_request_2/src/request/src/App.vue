<template>
  <div>
    <spa-header />
    <router-view />
  </div>
</template>

<script>
import header from "@/globals/Header.vue";

export default {
  components: {
    "spa-header": header,
  },
};
</script>

<style>
html,
body {
  font-family: "sans-serif";
}
</style>
