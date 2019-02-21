from flask import *

app = Flask("__app__")


@app.route("/url", methods=["GET", "POST"])
def main():
    params = request.args
    val1 = int(params['val1'])
    val2 = int(params['val2'])

    return make_response("The sum is: "+str(val1+val2), 200)


app.run("0.0.0.0", port=8000)
