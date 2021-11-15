#!/usr/bin/env bash

compile=asciidoctor

adoc_file=index.adoc
html_file=index.html
$compile $adoc_file
browser-sync start --server --no-notify --watch $html_file --index $html_file&

while true; do
    inotifywait *.adoc -e move_self && $compile $adoc_file
done
