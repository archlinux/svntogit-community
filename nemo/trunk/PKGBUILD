# Maintainer: Eli Schwartz <eschwartz@archlinux.org>
# Contributor: Alexandre Filgueira <alexfilgueira@cinnarch.com>
# Contributor: Ner0

pkgname=nemo
pkgver=4.6.3
pkgrel=1
pkgdesc="Cinnamon file manager (Nautilus fork)"
arch=('x86_64')
url="https://github.com/linuxmint/${pkgname}"
license=('GPL')
depends=('cinnamon-desktop' 'dconf' 'gvfs' 'exempi' 'libexif' 'libnotify' 'libxml2'
         'python' 'xapps')
optdepends=('cinnamon-translations: i18n'
            'ffmpegthumbnailer: support for video thumbnails')
makedepends=('meson' 'samurai' 'gobject-introspection' 'intltool')
source=("$pkgname-$pkgver.tar.gz::${url}/archive/${pkgver}.tar.gz")
sha512sums=('1cfed5e5ea7aa02376ea4958bf375951ee9b4005017eae60bf3efaf134b45b53bb56b8b64302b47b86375bbcb188b22998eaaf7a679dd8564b711fe1898817f3')
b2sums=('0748e3f8970280dd24788a51938e3515849e51cb4b2f4093c9bd37f74c3bec65c494d7a7c1d3c906c328bc03f5f26add7165dff48b7b728f84e14ebbba0d48e1')

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
