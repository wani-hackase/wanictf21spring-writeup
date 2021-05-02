stop:
	docker-compose stop

rm:
	docker-compose rm -f

build:
	docker-compose build --pull

pull:
	docker-compose pull

down:
	docker-compose down -v

dev:
	@make stop
	@make rm
	@make build
	@make pull
	docker-compose -f docker-compose.yml -f docker-compose.dev.yml up -d

prod:
	@make stop
	@make rm
	@make build
	@make pull
	docker-compose -f docker-compose.yml -f docker-compose.prod.yml up -d
