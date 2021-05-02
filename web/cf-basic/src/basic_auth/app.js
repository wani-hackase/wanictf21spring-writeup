let response;

/**
 *
 * Event doc: https://docs.aws.amazon.com/apigateway/latest/developerguide/set-up-lambda-proxy-integrations.html#api-gateway-simple-proxy-for-lambda-input-format
 * @param {Object} event - API Gateway Lambda Proxy Input Format
 *
 * Context doc: https://docs.aws.amazon.com/lambda/latest/dg/nodejs-prog-model-context.html 
 * @param {Object} context
 *
 * Return doc: https://docs.aws.amazon.com/apigateway/latest/developerguide/set-up-lambda-proxy-integrations.html
 * @returns {Object} object - API Gateway Lambda Proxy Output Format
 * 
 */
exports.handler = (event, context, callback) => {
    const request = event.Records[0].cf.request;
    const headers = request.headers;
    const authUser = '2U#2CNopSR';
    const authPass = 'mTqnD!86M*';
    const authString = 'Basic ' + new Buffer(`${authUser}:${authPass}`).toString('base64');
    if (typeof headers.authorization == 'undefined' || headers.authorization[0].value != authString) {
        const response = {
            status: '401',
            statusDescription: 'Unauthorized',
            body: 'Unauthorized',
            headers: {
                'www-authenticate': [{ key: 'WWW-Authenticate', value:'Basic' }],
            },
        };
        callback(null, response);
    } else {
        callback(null, request);
    }
};
