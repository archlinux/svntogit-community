# Maintainer: Eli Schwartz <eschwartz@archlinux.org>
# Contributor: Alexandre Filgueira <alexfilgueira@cinnarch.com>
# Contributor: Ner0

pkgname=nemo
pkgver=4.8.4
pkgrel=1
pkgdesc="Cinnamon file manager (Nautilus fork)"
arch=('x86_64')
url="https://github.com/linuxmint/${pkgname}"
license=('GPL')
depends=('cinnamon-desktop' 'dconf' 'gvfs' 'exempi' 'libexif' 'libnotify' 'libxml2'
         'python' 'xapp')
optdepends=('cinnamon-translations: i18n'
            'ffmpegthumbnailer: support for video thumbnails')
makedepends=('meson' 'samurai' 'gobject-introspection' 'intltool')
source=("$pkgname-$pkgver.tar.gz::${url}/archive/${pkgver}.tar.gz")
sha512sums=('b63ee2bd85f67e7d18271032ac3d95c7446b5110b71a3236f7e8c4ccb31e2baf11912060dde36f12ed4b90491c3bb1215a0de38c419130d692c775031cc0e11e')
b2sums=('10945a385defdf1bdc7fac9432306e31476ec015489a5150a5b4f9d5f31977b93da6e92241ce153cd5435c789c7a6ce16d2a86002758f26fc587a33dc5343e63')

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
    samu
}

package() {
    cd "${srcdir}"/${pkgname}-${pkgver}/build

    DESTDIR="${pkgdir}" samu install
}
