# Maintainer: Eli Schwartz <eschwartz@archlinux.org>
# Contributor: Felix Yan <felixonmars@archlinux.org>
# Contributor: Michael Hansen <zrax0111 gmail com>

pkgbase=keybase
pkgname=('keybase' 'kbfs' 'keybase-gui')
pkgdesc='CLI tool for GPG with keybase.io'
pkgver=5.7.1
pkgrel=2
arch=('x86_64')
url='https://keybase.io/'
license=('BSD')
# git is needed for yarn...
makedepends=('git' 'go' 'yarn')
source=("https://github.com/keybase/client/releases/download/v${pkgver}/${pkgbase}-v${pkgver}.tar.xz"{,.sig}
        "keybase-gui"
        "0001-Maintain-current-contextIsolation-behavior-across-el.patch"
        "0001-Don-t-use-electron-to-build.patch")
sha512sums=('1cdf93a2e52e16eedd7fe4544a2b1f0e6f6d47802e17e029ae08b19302c44d5cca0b297aa827332a62202045f91c7c6b1d9d627f2915fcdb4cc2a77076adbd0d'
            'SKIP'
            'dc52d7c3d5798d9b83a4e42ba70a071b1cd5cb95c8b695a4b7a33d85744762ae644feef58cf4d582c8d8c169be68d57f392c33ff0796490e88f01f09b4c207d2'
            '5cb3d93c4bb468fd47e1670f73cc3b8be14977ccf563a47d776285b6b9d96042647062427e58bd981727362caa23d17acdc0152dfd915efeeb6c4e76ca76ca65'
            'f759f69b774200261687842c66902a3c45638bb012ced9bd83d27491c8a0bbc0bc744dbb83ad7672d443f32d7303c15aeb0ded7a1a0d7ab56e7b1c1b64e263c3')
b2sums=('8f2501c3db8f0d3f82a5a597d1654af69a7d603b96d6143dc7df443290eb6b2ee299cc300f41061236b2738bc2a54018bc55705ddb903df326fd8850c12c506f'
        'SKIP'
        'ac27d14a9625a3bca6a4ac87adbe5bb2f0aee0c4a88bf39ac8b3d235801743b2e40e6cd7db26089398f016a25046a674f521b890ddf73c3c6637d0d6bf6e1397'
        '67f416c59b549606d037167c796c5b99f0ca9158fb767d52c101f41db6d31927b57618efb4d6eaf590cbd3c7aab4dd71a64bc3b52580e2383f5389c95264a499'
        '02d7876fb0d68b05e9ee262925a063049bfa2e5e063789008c4c74e406084d4441d2c860ecb2b08596f9d9a8c9a6e9136a2cdbd8312bcbf376d9d6e6c811bcfc')
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
    # New versions of electron tighten sandboxing and applications need to adapt.
    # Keybase did not, so loosen this back to pre v12 levels
    # https://github.com/keybase/client/pull/24551
    patch -p1 -i ../0001-Maintain-current-contextIsolation-behavior-across-el.patch
}

build() {
    cd client-v${pkgver}/go/keybase

    # None of this should be necessary, but we duplicate the work of
    # makepkg.conf here since golang CGO can't be bothered to respect
    # standardized CFLAGS and we don't have native packaging integration for
    # either this or the go-specific flags. Must be done here to make sure
    # we're using debug or !buildflags.

    export CGO_CPPFLAGS="${CPPFLAGS}"
    export CGO_CFLAGS="${CFLAGS}"
    export CGO_CXXFLAGS="${CXXFLAGS}"
    export CGO_LDFLAGS="${LDFLAGS}"
    export GOFLAGS="-buildmode=pie -trimpath -mod=readonly -modcacherw"

    export GO111MODULE=off

    export GOPATH="${srcdir}/.gopath"
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
