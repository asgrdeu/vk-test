#!/bin/zsh

glm_paths=$(find ./ -name glm)

git clone git@github.com:g-truc/glm.git tmp

echo $glm_paths | xargs -I{} rm -rf {}/\*
echo $glm_paths | xargs -I{} cp -r tmp/glm/* {}/

rm -rf tmp

echo "Done"
