# Maintainer: Bruno Pagani <archange@archlinux.org>
# Maintainer: Caleb Maclennan <alerque.com>
# Contributor: William Gathoye <william + aur at gathoye dot be>
# Contributor: Massimiliano Torromeo <massimiliano dot torromeo at gmail dot com>

pkgname=mattermost
pkgver=7.7.1
pkgrel=1
pkgdesc="Open source Slack-alternative in Golang and React"
arch=(x86_64)
url="https://mattermost.com"
license=(AGPL Apache)
depends=(glibc)
makedepends=(go jq nodejs-lts-gallium npm git python)
optdepends=('mariadb: SQL server storage'
            'mmctl: CLI admin tool'
            'percona-server: SQL server storage'
            'postgresql: SQL server storage')
options=(!lto)
backup=(etc/webapps/${pkgname}/config.json)
_server_archive="$pkgname-server-$pkgver"
_webapp_archive="$pkgname-webapp-$pkgver"
source=(https://github.com/$pkgname/$pkgname-server/archive/v$pkgver/$_server_archive.tar.gz
        https://github.com/$pkgname/$pkgname-webapp/archive/v$pkgver/$_webapp_archive.tar.gz
        $pkgname.service
        $pkgname.sysusers
        $pkgname.tmpfiles)
sha256sums=('89d3e38af6c71d73137e912862a77a17f993fb5389059bca5175786aba5436f8'
            'a5e761f3687c8a421f2987c594566cbf9ae2024a40e923fe36c02aa58aa1b0a6'
            '9e73dc5e9ab9a95049352bd504fb4e0d6becbd5c715026d8c1df4f515d258b68'
            'f7bd36f6d7874f1345d205c6dcb79af1804362fc977a658db88951a172d1dfa0'
            '8dfeee28655b91dc75aca2317846284013ac3d5a837d360eba9641e9fbcf3aa2')

prepare() {
    cd "$_server_archive"
    go mod vendor

    # The configuration isn’t available at this time yet, modify the default.
    sed -r -i build/release.mk \
        -e  's!config/config.json!config/default.json!' \
        -e 's/\$\(DIST_PATH\)\/config\/config.json/\$\(DIST_PATH\)\/config\/default.json/'

    # Don’t embed a precompiled mmctl
    sed '/@#Download MMCTL/,+2d' -i build/release.mk

    # Remove platform specific precompiled plugin downloads
    sed '/# Download prepackaged plugins/,+8d' -i build/release.mk

    cd "../$_webapp_archive"

    # Modify npm commands to always use srcdir cache + temporary workaround for OpenSSL3 support
    sed -r -i Makefile \
        -e "/^\tnpm /s!npm!npm --cache '$srcdir/npm-cache' --no-audit --no-fund!" \
        -e "s|--max-old-space-size=4096|--openssl-legacy-provider|"
    make node_modules -W package.json

    # Enforce build hash to Arch Linux for the field corresponding to the webapp.
    sed -r -i webpack.config.js \
        -e "s/^(\s*)COMMIT_HASH:(.*),$/\1COMMIT_HASH: JSON.stringify\(\"$pkgver-$pkgrel Arch Linux \($CARCH\)\"\),/"
}

build() {
    cd "$_server_archive"
    export CGO_CPPFLAGS="$CPPFLAGS"
    export CGO_CFLAGS="$CFLAGS"
    export CGO_CXXFLAGS="$CXXFLAGS"
    export CGO_LDFLAGS="$LDFLAGS"
    export GOFLAGS="-buildmode=pie -trimpath -mod=readonly -modcacherw"
    local _config=github.com/mattermost/mattermost-server/v6/model
    go build -v \
         -ldflags "-linkmode external
                   -X \"$_config.BuildNumber=$pkgver-$pkgrel\" \
                   -X \"$_config.BuildDate=$(date --utc --date="@${SOURCE_DATE_EPOCH:-$(date +%s)}" +"%Y-%m-%d %H:%M:%S")\" \
                   -X \"$_config.BuildHash=$pkgver-$pkgrel Arch Linux ($CARCH)\" \
                   -X \"$_config.BuildHashEnterprise=none\" \
                   -X \"$_config.BuildEnterpriseReady=false\"" \
         -o bin/ ./...
    # Move to the client directory to avoid LDFLAGS pollution of a `make build-client` invocation
    cd "../$_webapp_archive"
    make build
    cd "../$_server_archive"
    export BUILD_WEBAPP_DIR="$srcdir"/$_webapp_archive
    make package-prep
}

package() {
    # systemd files
    install -Dm644 $pkgname.service -t "$pkgdir"/usr/lib/systemd/system/
    install -Dm644 $pkgname.sysusers "$pkgdir"/usr/lib/sysusers.d/$pkgname.conf
    install -Dm644 $pkgname.tmpfiles "$pkgdir"/usr/lib/tmpfiles.d/$pkgname.conf

    # core stuff
    cd "$_server_archive"

    install -dm755 "$pkgdir"/usr/share/webapps
    cp -a dist/$pkgname "$pkgdir"/usr/share/webapps/

    install -Dm755 bin/$pkgname -t "$pkgdir"/usr/bin
    install -dm755 "$pkgdir"/usr/share/webapps/$pkgname/bin/
    ln -sf /usr/bin/$pkgname "$pkgdir"/usr/share/webapps/$pkgname/bin/$pkgname

    # fixes
    cd "$pkgdir"/usr/share/webapps/$pkgname

    # Move logs to right location
    rm -rf logs
    ln -s "/var/log/$pkgname" logs

    # Readme and docs
    install -dm755 "$pkgdir"/usr/share/doc/$pkgname
    mv NOTICE.txt README.md "$pkgdir"/usr/share/doc/$pkgname

    # Config file management
    cp config/default.json config/config.json

    # Hashtags are needed to escape the Bash escape sequence. jq will consider
    # it as a comment and won't interpret it.
    jq '.FileSettings.Directory |= $mmVarLib + "/files/" | # \
        .ComplianceSettings.Directory |= $mmVarLib + "/compliance/" | # \
        .PluginSettings.Directory |= $mmVarLib + "/plugins/" | # \
        .PluginSettings.ClientDirectory |= $mmVarLib + "/client/plugins/" | # \
        .LogSettings.FileLocation |= "/var/log/mattermost/" | # \
        .NotificationLogSettings.FileLocation |= "/var/log/mattermost/"' \
       --arg mmVarLib '/var/lib/mattermost' \
       config/config.json > config/config-new.json
    mv config/config-new.json config/config.json
    install -dm755 "$pkgdir"/etc/webapps
    mv config "$pkgdir"/etc/webapps/$pkgname
    ln -sf /etc/webapps/$pkgname config

    # Avoid access denied when Mattermost tries to rewrite its asset data
    # (root.html, manifest.json and *.css) during runtime. Reuse var tmpfile
    # directory SELinux security context.
    # cf. https://github.com/mattermost/mattermost-server/blob/f8d31def8eb463fcd866ebd08f3e6ef7a24e2109/utils/subpath.go#L48
    # cf. https://wiki.archlinux.org/index.php/Web_application_package_guidelines
    install -dm770 "$pkgdir"/var/lib/mattermost/client

    # We want recursivity as Mattermost wants to modify files in
    # client/files/code_themes/ as well.
    # Not recursive: for file in root.html manifest.json *.css; do
    find client -type f -iname 'root.html' -o -iname 'manifest.json' -o -iname '*.css' |
        while IFS= read -r fileAndPath; do
            install -dm770 "$pkgdir"/var/lib/mattermost/"${fileAndPath%/*}"
            install -m660 "$fileAndPath" "$pkgdir"/var/lib/mattermost/"${fileAndPath%/*}"
            rm "$fileAndPath"
            ln -s /var/lib/mattermost/"$fileAndPath" "$fileAndPath"
        done
}
