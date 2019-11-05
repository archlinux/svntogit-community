# Maintainer: Eli Schwartz <eschwartz@archlinux.org>
# Contributor: Felix Yan <felixonmars@archlinux.org>
# Contributor: Michael Hansen <zrax0111 gmail com>

pkgbase=keybase
pkgname=('keybase' 'kbfs' 'keybase-gui')
pkgdesc='CLI tool for GPG with keybase.io'
pkgver=4.7.2
pkgrel=1
arch=('x86_64')
url='https://keybase.io/'
license=('BSD')
# git is needed for yarn...
makedepends=('git' 'go-pie' 'yarn')
source=("https://github.com/keybase/client/releases/download/v${pkgver}/${pkgbase}-v${pkgver}.tar.xz"{,.sig}
        "keybase-gui"
        "0001-Don-t-use-electron-to-build.patch")
sha512sums=('edba96e7f1f5c38c8f38a55eff5e6266c01654149837cd6322eab700db2b24b5bd3bef4c6e92386f8bd581791a7ba96b49f8b53170cc7ea988702fa61674f96c'
            'SKIP'
            '4dcb3f4119959e2b203528a9ed637bf8b07b85964c632a8b2456aa1e2f29fada383a9bc2af8abbb05fcf6b22c43723ce6d08bea8187d61fa6581d15fefae850b'
            '32256b4cc3d2dd1ed645f58981db086af09cfe8d8f8e9d913c1d3731e249282dff699e545bf822e67abd4c36abc04130137e2b6f72877c898d75d602abd99fe7')
b2sums=('1cc7e330abb8a5f096d4fbab27afca003088d9d633db7733615092ea9cbd5c85e5a21ae58869db3121349a2531d59a3ca78c4d6e435fd30a9c49d172cfa56cb5'
        'SKIP'
        '90aab71ef3b5db0c8ec81967604f43e3532be5f66ce7d9af1bd5204c1fde2062ef356909c03d237a63de93fa3cb045b9c31c3956cbecbea711602804e9d26efd'
        'ffc92d422586ffaa4f1133889140e1ddf5ada0f05d77423c39b5d70bc98538bbe070e71bcfdf205959f929788f8971e60dc918aa3cdb74817b6a5ec21375b1d9')
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
