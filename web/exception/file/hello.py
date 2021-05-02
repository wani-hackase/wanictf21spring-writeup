import json
import os
import traceback

# HelloFunction(/hello)のコード
def lambda_handler(event, context):
    try:
        try:
            data = json.loads(event["body"])
        except Exception:
            data = {}
        if "name" in data:
            return {
                "statusCode": 200,
                "body": json.dumps({"name": "こんにちは、" + data["name"] + "さん"}),
            }
        return {
            "statusCode": 400,
            "body": json.dumps(
                {
                    "error_message": "Bad Request",
                }
            ),
        }
    except Exception as e:
        error_message = traceback.format_exception_only(type(e), e)
        del event["requestContext"]["accountId"]
        del event["requestContext"]["resourceId"]
        return {
            "statusCode": 500,
            "body": json.dumps(
                {
                    "error_message": error_message,
                    "event": event,
                    "flag": os.environ.get("FLAG"),
                }
            ),
        }
