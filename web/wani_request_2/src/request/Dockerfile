FROM node:15.8.0-alpine as build-stage

WORKDIR /app

COPY package.json ./

COPY package-lock.json ./

RUN npm install

COPY . .

RUN npm run build

FROM nginx:alpine as production-stage

COPY --from=build-stage /app/dist /usr/share/nginx/html

COPY default.conf /etc/nginx/conf.d/default.conf
