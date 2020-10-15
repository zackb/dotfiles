# Hackup

### A really dirty backup script.
Using [s3fs](https://github.com/s3fs-fuse/s3fs-fuse) to backup a list of directories to an S3 compatible object store. Using rsync?

s3fs BUCKET PATH \
    -o url=https://s3.us-west-002.backblazeb2.com \
    -o nomixupload


s3fs hackup /Volumes/hackup -o url=https://s3.us-west-002.backblazeb2.com -o nomixupload
