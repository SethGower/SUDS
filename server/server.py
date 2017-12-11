from flask import Flask, request

app = Flask(__name__)


@app.route("/", methods=["GET"])
def parse_json():
    return 'Fuck you'


@app.route("/post", methods=["POST"])
def test():
    if request.is_json:
        content = request.get_json();
        print(content)
        return "Received"
