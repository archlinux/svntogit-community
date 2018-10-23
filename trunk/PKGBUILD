# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Maintainer: Eli Schwartz <eschwartz@archlinux.org>
# Contributor: Michael Hansen <zrax0111 gmail com>

pkgbase=keybase
pkgname=('keybase' 'keybase-gui')
pkgdesc='CLI tool for GPG with keybase.io'
pkgver=2.8.0
pkgrel=1
arch=('x86_64')
url='https://keybase.io/'
license=('BSD')
# git is needed for yarn...
makedepends=('git' 'go-pie' 'yarn')
source=("${pkgname}-${pkgver}.tar.gz::https://github.com/keybase/client/archive/v${pkgver}.tar.gz"
        "keybase-gui"
        "0001-Don-t-use-electron-to-build.patch")
sha512sums=('01319ee36d50d928e195d854a3c332d7f327cabd8cdf930f643f3d373a6bd644634a56137f5f02477c15fc261cee3c01cb87efbb80333b7c7299a2048d9f1be1'
            'b3086ea6c60950284eecc331a8a648ea557f89f686f2adecb82b22d0ac65381683fbcc84875a48cf6ba9e3c63d4f06c73b84175621dca5e8f03b2a6a88cdcad4'
            '076cbb73495f6df5b4c54f77c62ee2ccd9b485f837bf5c2206063b79f76814b1bc65910e031ac252b14e88531e50506acffe7608b00e01c7ae724de7f510a574')

prepare() {
    cd client-${pkgver}

    export GOPATH="${srcdir}/.gopath"
    mkdir -p "${GOPATH}"/src/github.com/keybase
    ln -sf "${PWD}" "${GOPATH}"/src/github.com/keybase/client

    # Fix paths to run electron /path/to/app (or our minimal wrapper script)
    sed -i 's@/opt/keybase/Keybase@/usr/bin/electron /usr/share/keybase-app@' \
        packaging/linux/systemd/keybase.gui.service
    sed -i 's/run_keybase/keybase-gui/g' \
        packaging/linux/keybase.desktop go/install/install_unix.go

    patch -p1 -i ../0001-Don-t-use-electron-to-build.patch
}

build() {
    cd client-${pkgver}/go/keybase

    export GOPATH="${srcdir}/.gopath"
    # go build -a -tags production -gccgoflags "$CFLAGS $LDFLAGS" github.com/keybase/client/go/keybase
    go build -a -tags production -o ../bin/keybase github.com/keybase/client/go/keybase
    go build -a -tags production -o ../bin/kbnm github.com/keybase/client/go/kbnm

    cd ../../shared
    yarn install
    yarn run package
}

package_keybase() {
    depends=('gnupg')
    optdepends=('kbfs: for the fuse-based fileystem and the encryption subcommand')

    cd client-${pkgver}

    install -Dm755 -t "${pkgdir}"/usr/bin/ go/bin/*

    # native messaging whitelists
    KBNM_INSTALL_ROOT=1 KBNM_INSTALL_OVERLAY="${pkgdir}" "${pkgdir}/usr/bin/kbnm" install
    # systemd activation
    install -Dm644 packaging/linux/systemd/keybase.service "${pkgdir}"/usr/lib/systemd/user/keybase.service
    install -Dm644 LICENSE "${pkgdir}"/usr/share/licenses/${pkgname}/LICENSE
}

package_keybase-gui() {
    pkgdesc="GUI frontend for GPG with keybase.io"
    depends=('electron' 'keybase' 'kbfs')

    cd client-${pkgver}/

    install -Dm644 packaging/linux/keybase.desktop \
        "${pkgdir}"/usr/share/applications/keybase.desktop
    # more systemd activation
    install -Dm644 packaging/linux/systemd/keybase.gui.service \
        "${pkgdir}"/usr/lib/systemd/user/keybase.gui.service
    # wrapper for electron
    install -Dm755 "${srcdir}"/keybase-gui "${pkgdir}"/usr/bin/keybase-gui

    install -Dm644 LICENSE "${pkgdir}"/usr/share/licenses/${pkgname}/LICENSE

    for i in 16 32 128 256 512 ; do
        install -Dm644 media/icons/Keybase.iconset/icon_${i}x${i}.png \
            "${pkgdir}"/usr/share/icons/hicolor/${i}x${i}/apps/keybase.png
    done
    # ???
    install -Dm644 media/icons/Keybase.iconset/icon_32x32@2x.png \
        "${pkgdir}"/usr/share/icons/hicolor/64x64/apps/keybase.png
    install -Dm644 media/icons/Keybase.iconset/icon_512x512@2x.png \
        "${pkgdir}"/usr/share/icons/hicolor/1024x1024/apps/keybase.png

    # the app itself
    cd shared/desktop/build
    rm -rf desktop/sourcemaps/
    mkdir -p "${pkgdir}"/usr/share/keybase-app
    cp -r * "${pkgdir}"/usr/share/keybase-app/
}
