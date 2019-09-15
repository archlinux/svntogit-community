# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Maintainer: Eli Schwartz <eschwartz@archlinux.org>
# Contributor: Michael Hansen <zrax0111 gmail com>

pkgbase=keybase
pkgname=('keybase' 'kbfs' 'keybase-gui')
pkgdesc='CLI tool for GPG with keybase.io'
pkgver=4.4.2
pkgrel=1
arch=('x86_64')
url='https://keybase.io/'
license=('BSD')
# git is needed for yarn...
makedepends=('git' 'go-pie' 'yarn')
source=("https://github.com/keybase/client/releases/download/v${pkgver}/${pkgbase}-v${pkgver}.tar.xz"{,.sig}
        "keybase-gui"
        "0001-Don-t-use-electron-to-build.patch")
sha512sums=('fccde8b8d2ee2cfe404f86f8314accee26afe5941833e2f1c5af5d0a0c66cbd475df9ce6a74ca1f0bba4bea3dffc64cd865156ef11a012797eaebc43eef9abaf'
            'SKIP'
            '4dcb3f4119959e2b203528a9ed637bf8b07b85964c632a8b2456aa1e2f29fada383a9bc2af8abbb05fcf6b22c43723ce6d08bea8187d61fa6581d15fefae850b'
            '747f87b6a399375331acb86d6a1beddf83496cab8a598aaa54e4fe7a096a8964b3cbd757bb6924b286a16cd68b9f081f917233c9ff2b984a1f92ef85aa9dd0bd')
b2sums=('88f44103e4193b31f5c1842bbc6c01d92e8f681731f878f0db3b0cf8997fce074689fab66888bd262affe0cc62c191255d946b292db36586794e37be6f855cb6'
        'SKIP'
        '90aab71ef3b5db0c8ec81967604f43e3532be5f66ce7d9af1bd5204c1fde2062ef356909c03d237a63de93fa3cb045b9c31c3956cbecbea711602804e9d26efd'
        'b20b444b58cc78c2960cc31cd070afae6b73d59e77afa76ab83167befd07b6ca91bdb1465d2d898ac61127c77fdbb708f48c591d053830883fbbaba660328de4')
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
