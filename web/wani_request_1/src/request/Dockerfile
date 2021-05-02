FROM alpine:3.11
RUN apk add --no-cache \
    chromium \
    nss \
    freetype \
    freetype-dev \
    harfbuzz \
    ca-certificates \
    ttf-freefont \
    nodejs \
    npm
ENV PUPPETEER_SKIP_CHROMIUM_DOWNLOAD=true \
    PUPPETEER_EXECUTABLE_PATH=/usr/bin/chromium-browser
WORKDIR /app
RUN npm i -g yarn
COPY package.json ./
COPY yarn.lock ./
RUN yarn
COPY . .
CMD [ "yarn", "start" ]