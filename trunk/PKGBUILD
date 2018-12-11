# Maintainer: Eli Schwartz <eschwartz@archlinux.org>
# Contributor: Alexandre Filgueira <alexfilgueira@cinnarch.com>
# Contributor: Ner0

pkgname=nemo
pkgver=4.0.5
pkgrel=1
pkgdesc="Cinnamon file manager (Nautilus fork)"
arch=('x86_64')
url="https://github.com/linuxmint/${pkgname}"
license=('GPL')
depends=('cinnamon-desktop' 'dconf' 'gvfs' 'exempi' 'libexif' 'libnotify' 'libxml2' 'python' 'xapps')
optdepends=('cinnamon-translations: i18n'
            'ffmpegthumbnailer: support for video thumbnails')
makedepends=('meson' 'gobject-introspection' 'intltool')
source=("$pkgname-$pkgver.tar.gz::${url}/archive/${pkgver}.tar.gz")
sha512sums=('8969f53c2714625fdcf6de8140cd062b0f196c64d69f9eea18088ef10a1e3e7ba466af7894b5e32e33db109eacad9e6b58e39e88763490621d8dff7360e63348')

prepare() {
    cd "${srcdir}"/${pkgname}-${pkgver}

    # Rename 'Files' app name to avoid having the same as nautilus
    sed -i '/^\[Desktop Entry/,/^\[Desktop Action/ s/^Name\(.*\)=.*/Name\1=Nemo/' data/nemo.desktop.in
}

build() {
    mkdir -p "${srcdir}"/${pkgname}-${pkgver}/build
    cd "${srcdir}"/${pkgname}-${pkgver}/build

    meson --prefix=/usr \
          --libexecdir=lib/${pkgname} \
          --buildtype=plain \
          ..
    ninja
}

package() {
    cd "${srcdir}"/${pkgname}-${pkgver}/build

    DESTDIR="${pkgdir}" ninja install
}
