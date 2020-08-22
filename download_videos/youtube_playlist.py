#regex original source http://code.activestate.com/recipes/578284-youtube-playlist-parserextractor/
#fork of https://gist.github.com/fffaraz/f3dcf48ae93b6c04adb9d74b1de711e5

#if you want to stream a yt-playlist with vlc use "python parser.py URLHERE -o playlist.m3u && cvlc --no-video playlist.m3u"


import re
import requests
import argparse

def getPlaylistLinks(url: str) -> map:
    # since it uses a set it's not ordered
    # since youtube doesn't provide more than 100 links at the time for the moment
    # it returns up to 100 elements
    page_text = requests.get(url).text

    parser = re.compile(r"watch\?v=\S+?list=")
    playlist = set(re.findall(parser, page_text))
    playlist = map(
        (lambda x: "https://www.youtube.com/" + x.replace("\\u0026list=", "")), playlist
    )
    return playlist


def is_yt_playlist(url: str):
    if not url.startswith("https://www.youtube.com/playlist?list="):
        raise argparse.ArgumentTypeError(
            "please use this format:"
            " https://www.youtube.com/playlist?list=XXXXXX....-XXXX..."
        )
    else:
        return url


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="Return a url-list from a youtube playlist"
    )
    parser.add_argument(
        "url", type=is_yt_playlist, nargs=1, help="an integer for the accumulator"
    )
    parser.add_argument("-o", type=str, nargs=1, help="optional output file")
    
    args = parser.parse_args()

    output = getPlaylistLinks(*args.url)
    
    if args.o:
        with open(args.o[0], "w") as f:
            f.writelines("\n".join(output))
            f.close()

    else:
        print(*output, sep="\n")

# python *.py url
