<template>
  <b-container class="mt-3">
    <p>URLを入力してください。</p>
    <b-form-textarea
      id="textarea"
      v-model="text"
      placeholder="enter text"
      rows="1"
      max-rows="2"
    ></b-form-textarea>

    <p>
      入力したURL: <a id="link" v-bind:href="text">{{ text }}</a>
    </p>
    <p>あどみんちゃんに入力したURLのリンクをクリックしてもらう</p>
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
      text: "https://www.google.com/",
      res: "送信してね",
      buttonLoading: false,
      token: ""
    };
  },
  components: {
    VueRecaptcha
  },
  methods: {
    submit: function() {
      this.buttonLoading = true;
      this.res = "送信中";
      if (this.token === "") {
        this.res = "recaptchaしてください";
        this.buttonLoading = false;
        return;
      }
      axios
        .post("/api/page2", {
          text: this.text,
          token: this.token
        })
        .then(response => {
          this.buttonLoading = false;
          this.res = response.data;
        })
        .catch(error => {
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
    }
  }
};
</script>
