# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Maintainer: Eli Schwartz <eschwartz@archlinux.org>
# Contributor: Michael Hansen <zrax0111 gmail com>

pkgbase=keybase
pkgname=('keybase' 'kbfs' 'keybase-gui')
pkgdesc='CLI tool for GPG with keybase.io'
pkgver=4.3.1
pkgrel=3
arch=('x86_64')
url='https://keybase.io/'
license=('BSD')
# git is needed for yarn...
makedepends=('git' 'go-pie' 'yarn')
source=("${pkgbase}-${pkgver}.tar.gz::https://github.com/keybase/client/archive/v${pkgver}.tar.gz"
        "https://github.com/keybase/client/commit/753d4ac4033f457bb43bb107014b2e9c76090015.patch"
        "keybase-gui"
        "0001-Don-t-use-electron-to-build.patch")
sha512sums=('6d5f303e42ee99377c59e322c61d61126ba09964ce690289a93939d6e85b9051f3e5367d96d2145aa716cd3ef329ede68f2aa6f7e2c8d19f85b55a92306a24bf'
            '2fb645efb208191cec3d4754119c59504980e703750051a38a1e4ba99a862a2626cca14be02959457f5d50ba752191c6d6466fd06babd661c104ecbe852c193e'
            '4dcb3f4119959e2b203528a9ed637bf8b07b85964c632a8b2456aa1e2f29fada383a9bc2af8abbb05fcf6b22c43723ce6d08bea8187d61fa6581d15fefae850b'
            '747f87b6a399375331acb86d6a1beddf83496cab8a598aaa54e4fe7a096a8964b3cbd757bb6924b286a16cd68b9f081f917233c9ff2b984a1f92ef85aa9dd0bd')
b2sums=('42a1d55d223a3c52d2aaced1c756814646cdb493447ba99d0b9a8267c83b67949d969e18a61bfdeb68e790561430a214bb284a93ac7d146d59ed1b2e97336bf2'
        '86871257c22f77158ce4644ad7f81ae3db1645df003b41bd5847dd34035a39d3e16ffbc64a67a6d1cf0eaa8fbf6d9047dee8846120587e9b4c6fb373242d131d'
        '90aab71ef3b5db0c8ec81967604f43e3532be5f66ce7d9af1bd5204c1fde2062ef356909c03d237a63de93fa3cb045b9c31c3956cbecbea711602804e9d26efd'
        'b20b444b58cc78c2960cc31cd070afae6b73d59e77afa76ab83167befd07b6ca91bdb1465d2d898ac61127c77fdbb708f48c591d053830883fbbaba660328de4')

prepare() {
    cd client-${pkgver}

    # support keybase:// links in argv2 with debundled electron
    # https://github.com/keybase/client/issues/18925
    patch -p1 -i ../753d4ac4033f457bb43bb107014b2e9c76090015.patch

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
    cd client-${pkgver}/go/keybase

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

    cd client-${pkgver}

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

    cd client-${pkgver}

    install -Dm755 -t "${pkgdir}"/usr/bin/ go/bin/{kbfsfuse,git-remote-keybase}
    install -Dm644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
    # more systemd activation
    install -Dm644 packaging/linux/systemd/kbfs.service "$pkgdir"/usr/lib/systemd/user/kbfs.service
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
