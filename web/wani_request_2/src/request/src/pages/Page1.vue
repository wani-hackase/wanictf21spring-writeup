<template>
  <b-container class="mt-3">
    <p>wani=<span id="wani"></span></p>

    <p>
      <b-form-input v-model="request" type="text" placeholder="クエリを入力してください"></b-form-input
      >
      あどみんちゃんに <code>https://request2.web.wanictf.org/page1?wani={{request}}</code> へアクセスしてもらう
    </p>
    <vue-recaptcha
      ref="recaptcha"
      @verify="onVerify"
      @expired="onExpired"
      sitekey="6LdbEbwaAAAAADxUPtj9hw5ftgvkZaCpUTX9YEp-"
    ></vue-recaptcha>
    <b-button variant="primary" v-on:click="submit" :disabled="buttonLoading">
      <b-spinner small v-if="buttonLoading"></b-spinner>
      送信
    </b-button>
    <p>あどみんちゃんの反応: {{ res }}</p>
  </b-container>
</template>

<script>
import axios from "axios";
import VueRecaptcha from "vue-recaptcha";

export default {
  data() {
    return {
      msg: this.$route.query.wani,
      request: "",
      res: "送信してね",
      buttonLoading: false,
      token: "",
    };
  },
  components: {
    VueRecaptcha,
  },
  mounted() {
    var wani = document.getElementById("wani");
    wani.innerHTML = this.msg;
  },
  methods: {
    submit() {
      this.buttonLoading = true;
      this.res = "送信中";
      if (this.token === "") {
        this.res = "recaptchaしてください";
        this.buttonLoading = false;
        return;
      }
      axios
        .post("/api/page1", {
          wani: this.request,
          token: this.token,
        })
        .then((response) => {
          this.buttonLoading = false;
          this.res = response.data;
        })
        .catch((error) => {
          this.buttonLoading = false;
          this.res = error;
        })
        .then(() => {
          this.resetRecaptcha();
        });
    },
    onVerify(response) {
      this.token = response;
    },
    onExpired() {
      console.log("Expired");
    },
    resetRecaptcha() {
      this.$refs.recaptcha.reset();
    },
  },
};
</script>
