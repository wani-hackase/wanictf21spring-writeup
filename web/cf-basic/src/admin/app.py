import os

def lambda_handler(event, context):
    return {
        "statusCode": 200,
        "headers": {
            "Content-Type": 'text/plain'
        },
        "body": os.environ.get('FLAG'),
    }
