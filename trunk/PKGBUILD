# Maintainer: Bruno Pagani <archange@archlinux.org>
# Maintainer: Caleb Maclennan <alerque.com>
# Contributor: William Gathoye <william + aur at gathoye dot be>
# Contributor: Massimiliano Torromeo <massimiliano dot torromeo at gmail dot com>

pkgname=mattermost
pkgver=5.39.1
pkgrel=1
pkgdesc="Open source Slack-alternative in Golang and React"
arch=(x86_64)
url="https://mattermost.com"
license=(AGPL Apache)
depends=(glibc)
makedepends=(go jq nodejs npm git python)
optdepends=('mariadb: SQL server storage'
            'percona-server: SQL server storage'
            'postgresql: SQL server storage')
backup=(etc/webapps/${pkgname}/config.json)
source=(${pkgname}-server-${pkgver}.tar.gz::https://github.com/${pkgname}/${pkgname}-server/archive/v${pkgver}.tar.gz
        ${pkgname}-webapp-${pkgver}.tar.gz::https://github.com/${pkgname}/${pkgname}-webapp/archive/v${pkgver}.tar.gz
        ${pkgname}.service
        ${pkgname}.sysusers
        ${pkgname}.tmpfiles)
sha256sums=('dca83e2a95a34500e14e6711a585e213474bb0f0f83b254dbb28ffdea3453f7c'
            '06ccf4b879d7d6c5ffe7ea5403deb4a417da0b5ca191b8dab23f68aff4d00973'
            'e5ba4a4f9c5f32816b997d5c02f6ddf3ef1e8259ae8dff5ef18865d076b70316'
            'f7bd36f6d7874f1345d205c6dcb79af1804362fc977a658db88951a172d1dfa0'
            '8dfeee28655b91dc75aca2317846284013ac3d5a837d360eba9641e9fbcf3aa2')

prepare() {
    cd ${pkgname}-server-${pkgver}
    go mod vendor

    # The configuration isn’t available at this time yet, modify the default.
    sed -r -i build/release.mk \
        -e  's!config/config.json!config/default.json!' \
        -e 's/\$\(DIST_PATH\)\/config\/config.json/\$\(DIST_PATH\)\/config\/default.json/'

    # Don’t embed a precompiled mmctl
    sed '/@#Download MMCTL/,+2d' -i build/release.mk
    # Remove platform specific lines from the Makefile from the line beginning
    # with that statement to the end of file (we do not care of the additional
    # file copy, nor the tar compression defined below the file).
    sed '/# Download prepackaged plugins/,//d' -i build/release.mk

    # Enforce build hash to Arch Linux for the field corresponding to the webapp.
    cd ../${pkgname}-webapp-${pkgver}
    sed -r -i webpack.config.js \
        -e "s/^(\s*)COMMIT_HASH:(.*),$/\1COMMIT_HASH: JSON.stringify\(\"${pkgver}-${pkgrel} Arch Linux \(${CARCH}\)\"\),/"
}

build() {
    cd ${pkgname}-server-${pkgver}
    export CGO_CPPFLAGS="${CPPFLAGS}"
    export CGO_CFLAGS="${CFLAGS}"
    export CGO_CXXFLAGS="${CXXFLAGS}"
    export CGO_LDFLAGS="${LDFLAGS}"
    export GOFLAGS="-buildmode=pie -trimpath -mod=readonly -modcacherw"
    go build -v \
         -ldflags "-linkmode external
                   -X \"github.com/mattermost/mattermost-server/v5/model.BuildNumber=${pkgver}-${pkgrel}\" \
                   -X \"github.com/mattermost/mattermost-server/v5/model.BuildDate=$(date --utc --date="@${SOURCE_DATE_EPOCH:-$(date +%s)}" +"%Y-%m-%d %H:%M:%S")\" \
                   -X \"github.com/mattermost/mattermost-server/v5/model.BuildHash=${pkgver}-${pkgrel} Arch Linux (${CARCH})\" \
                   -X \"github.com/mattermost/mattermost-server/v5/model.BuildHashEnterprise=none\" \
                   -X \"github.com/mattermost/mattermost-server/v5/model.BuildEnterpriseReady=false\"" \
         -o bin/ ./...
    # Move to the client directory to avoid LDFLAGS pollution of a `make build-client` invocation
    cd ../${pkgname}-webapp-${pkgver}
    make build
    cd ../${pkgname}-server-${pkgver}
    export BUILD_WEBAPP_DIR="${srcdir}"/${pkgname}-webapp-${pkgver}
    make package
}

package() {
    # systemd files
    install -Dm644 ${pkgname}.service -t "${pkgdir}"/usr/lib/systemd/system/
    install -Dm644 ${pkgname}.sysusers "${pkgdir}"/usr/lib/sysusers.d/${pkgname}.conf
    install -Dm644 ${pkgname}.tmpfiles "${pkgdir}"/usr/lib/tmpfiles.d/${pkgname}.conf

    # core stuff
    cd ${pkgname}-server-${pkgver}

    install -dm755 "${pkgdir}"/usr/share/webapps
    cp -a dist/${pkgname} "${pkgdir}"/usr/share/webapps/

    install -Dm755 bin/${pkgname} -t "${pkgdir}"/usr/bin
    install -dm755 "${pkgdir}"/usr/share/webapps/${pkgname}/bin/
    ln -sf /usr/bin/${pkgname} "${pkgdir}"/usr/share/webapps/${pkgname}/bin/${pkgname}

    # fixes
    cd "${pkgdir}"/usr/share/webapps/${pkgname}

    # Move logs to right location
    rm -rf logs
    ln -s "/var/log/${pkgname}" logs

    # Readme and docs
    install -dm755 "${pkgdir}"/usr/share/doc/${pkgname}
    mv NOTICE.txt README.md "${pkgdir}"/usr/share/doc/${pkgname}

    # Config file management
    cp config/default.json config/config.json

    # Hashtags are needed to escape the Bash escape sequence. jq will consider
    # it as a comment and won't interpret it.
    jq '.FileSettings.Directory |= $mmVarLib + "/files/" | # \
        .ComplianceSettings.Directory |= $mmVarLib + "/compliance/" | # \
        .PluginSettings.Directory |= $mmVarLib + "/plugins/" | # \
        .PluginSettings.ClientDirectory |= $mmVarLib + "/client/plugins/"' \
       --arg mmVarLib '/var/lib/mattermost' \
       config/config.json > config/config-new.json
    mv config/config-new.json config/config.json
    install -dm755 "${pkgdir}"/etc/webapps
    mv config "${pkgdir}"/etc/webapps/${pkgname}
    ln -sf /etc/webapps/${pkgname} config

    # Avoid access denied when Mattermost tries to rewrite its asset data
    # (root.html, manifest.json and *.css) during runtime. Reuse var tmpfile
    # directory SELinux security context.
    # cf. https://github.com/mattermost/mattermost-server/blob/f8d31def8eb463fcd866ebd08f3e6ef7a24e2109/utils/subpath.go#L48
    # cf. https://wiki.archlinux.org/index.php/Web_application_package_guidelines
    install -dm770 "${pkgdir}"/var/lib/mattermost/client

    # We want recursivity as Mattermost wants to modify files in
    # client/files/code_themes/ as well.
    # Not recursive: for file in root.html manifest.json *.css; do
    find client -type f -iname 'root.html' -o -iname 'manifest.json' -o -iname '*.css' |
        while IFS= read -r fileAndPath; do
            install -dm770 "${pkgdir}"/var/lib/mattermost/"${fileAndPath%/*}"
            install -m660 "${fileAndPath}" "${pkgdir}"/var/lib/mattermost/"${fileAndPath%/*}"
            rm "${fileAndPath}"
            ln -s /var/lib/mattermost/"${fileAndPath}" "${fileAndPath}"
        done
}
