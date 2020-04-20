# Maintainer: Eli Schwartz <eschwartz@archlinux.org>
# Contributor: Felix Yan <felixonmars@archlinux.org>
# Contributor: Michael Hansen <zrax0111 gmail com>

pkgbase=keybase
pkgname=('keybase' 'kbfs' 'keybase-gui')
pkgdesc='CLI tool for GPG with keybase.io'
pkgver=5.4.0
pkgrel=1
arch=('x86_64')
url='https://keybase.io/'
license=('BSD')
# git is needed for yarn...
makedepends=('git' 'go-pie' 'yarn')
source=("https://github.com/keybase/client/releases/download/v${pkgver}/${pkgbase}-v${pkgver}.tar.xz"{,.sig}
        "keybase-gui"
        "0001-Don-t-use-electron-to-build.patch")
sha512sums=('5b0ae52a38fb9ce84a4d5fb53ad0824f03be0f1a8f0b86c4e4e07bf07e814d2accf46fd1a9b0001db5a331866b5414f7d1c59ae7f3ee13348fe97079acf6f883'
            'SKIP'
            'd672bdd308b2ab6f7b1248300f85f11b480e08149e1e4da5e01dac6c551b44dbfceb5c89d0fd17ce7a64c8b83cd4c7df14e24c31c2f37ae532abbb9099320290'
            '1485e41432218b88aff71bbe68d265baad18c8b91b3d51cacdb4ac9b09abfb6cde91b9b87cb861cffeff92830159552307a89462c8697bb066416bd897e7b68b')
b2sums=('d11f94ef3ee769701d590f8a1ee44d1221cc0d1825aff3fbbb4b7c55bee692ecd4b8b15439d1197a9b17f98661f19c4b53fe1daa73d26fa437003303033498e6'
        'SKIP'
        'db6d63df77aa73c230128b5c6cd278215e0dfac2b42db861127571a6c867d8a305c18a5ea12a616669c77bd072ab8b26aa52379cbd8167c34bc043bfdcefec1d'
        '164dd6f37fe38d3c840b2b92d41553e0be67985d7c8471833a9ff381c05b0c35f295bfc630aa3ce6e31afb70b805d071e8c0a438a504064d24f99720c1571b9a')
validpgpkeys=('222B85B0F90BE2D24CFEB93F47484E50656D16C7') # Keybase.io Code Signing (v1) <code@keybase.io>

prepare() {
    cd client-v${pkgver}

    export GOPATH="${srcdir}/.gopath"
    mkdir -p "${GOPATH}"/src/github.com/keybase
    ln -sf "${PWD}" "${GOPATH}"/src/github.com/keybase/client

    # Fix paths to run electron /path/to/app (or our minimal wrapper script).
    # Also wire up "hideWindow" when running as a service or via XDG autostart.
    sed -i 's@/opt/keybase/Keybase@/usr/bin/electron /usr/share/keybase-app@' \
        packaging/linux/systemd/keybase.gui.service
    sed -i 's/run_keybase/keybase-gui/g' \
        packaging/linux/keybase.desktop go/install/install_unix.go

    patch -p1 -i ../0001-Don-t-use-electron-to-build.patch
}

build() {
    cd client-v${pkgver}/go/keybase

    export GOPATH="${srcdir}/.gopath"
    # go build -a -tags production -gccgoflags "$CFLAGS $LDFLAGS" github.com/keybase/client/go/keybase
    go build -a -tags production -o ../bin/keybase github.com/keybase/client/go/keybase
    go build -a -tags production -o ../bin/kbnm github.com/keybase/client/go/kbnm
    go build -a -tags production -o ../bin/kbfsfuse github.com/keybase/client/go/kbfs/kbfsfuse
    go build -a -tags production -o ../bin/git-remote-keybase github.com/keybase/client/go/kbfs/kbfsgit/git-remote-keybase

    cd ../../shared
    yarn install
    yarn run package --appVersion $pkgver
}

package_keybase() {
    depends=('gnupg')
    optdepends=('kbfs: for the fuse-based fileystem and the encryption subcommand')

    cd client-v${pkgver}

    install -Dm755 -t "${pkgdir}"/usr/bin/ go/bin/{keybase,kbnm}

    # native messaging whitelists
    KBNM_INSTALL_ROOT=1 KBNM_INSTALL_OVERLAY="${pkgdir}" "${pkgdir}/usr/bin/kbnm" install
    # systemd activation
    install -Dm644 packaging/linux/systemd/keybase.service "${pkgdir}"/usr/lib/systemd/user/keybase.service
    install -Dm644 LICENSE "${pkgdir}"/usr/share/licenses/${pkgname}/LICENSE
}

package_kbfs() {
    pkgdesc="The Keybase filesystem"
    url="https://keybase.io/docs/kbfs"
    depends=('fuse' 'keybase')
    install=kbfs.install

    cd client-v${pkgver}

    install -Dm755 -t "${pkgdir}"/usr/bin/ go/bin/{kbfsfuse,git-remote-keybase}
    install -Dm644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
    # more systemd activation
    install -Dm644 packaging/linux/systemd/kbfs.service "$pkgdir"/usr/lib/systemd/user/kbfs.service
}

package_keybase-gui() {
    pkgdesc="GUI frontend for GPG with keybase.io"
    depends=('electron' 'keybase' 'kbfs')

    cd client-v${pkgver}/

    install -Dm644 packaging/linux/x-saltpack.xml \
        "${pkgdir}"/usr/share/mime/packages/x-saltpack.xml
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
        install -Dm644 media/icons/Saltpack.iconset/icon_${i}x${i}.png \
            "${pkgdir}"/usr/share/icons/hicolor/${i}x${i}/mimetypes/application-x-saltpack.png
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
