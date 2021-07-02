# Maintainer: Eli Schwartz <eschwartz@archlinux.org>
# Contributor: Alexandre Filgueira <alexfilgueira@cinnarch.com>
# Contributor: Ner0

pkgname=nemo
pkgver=5.0.3
pkgrel=1
pkgdesc="Cinnamon file manager (Nautilus fork)"
arch=('x86_64')
url="https://github.com/linuxmint/${pkgname}"
license=('GPL')
depends=('cinnamon-desktop' 'dconf' 'gvfs' 'exempi' 'libexif' 'libnotify' 'libxml2'
         'python' 'xapp')
optdepends=('cinnamon-translations: i18n'
            'ffmpegthumbnailer: support for video thumbnails'
            'catdoc: search helpers support for legacy MS Office files'
            'ghostscript: search helpers support for PostScript files'
            'libgsf: search helpers support for MS Office files'
            'libreoffice: search helpers support for legacy MS Office powerpoint files'
            'odt2txt: search helpers support for LibreOffice files'
            'poppler: search helpers support for PDF')
makedepends=('meson' 'samurai' 'gobject-introspection' 'intltool' 'libgsf')
source=("$pkgname-$pkgver.tar.gz::${url}/archive/${pkgver}.tar.gz")
sha512sums=('f2f2c01338afe5ac50cc2babff323b2920c347d7b9c4d56bec005e90b517464d59f63ae0c4ce69ceab8689f6e762c20f6bd04ead4879b42c686270b82b2bb8d2')
b2sums=('10a08aead870cc4d3b4600478038829bc55c5a3f934ac401e2471d2a5abb085439518eb869e3f35d67c58a669cce968438f4b604e90b48344e275d05b1792177')

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
