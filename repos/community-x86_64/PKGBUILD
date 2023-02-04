# Maintainer : Daniel Bermond <dbermond@archlinux.org>
# Contributor: Gaetan Bisson
# Contributor: damir

pkgname=x11vnc
pkgver=0.9.16
pkgrel=7
epoch=1
_commit='4ca006fed80410bd9b061a1519bd5d9366bb0bc8'
pkgdesc='VNC server for real X displays'
url='https://github.com/LibVNC/x11vnc'
arch=('x86_64')
license=('GPL')
depends=('libvncserver' 'openssl' 'libxcrypt' 'libxtst' 'libxext' 'libxinerama'
         'libxrandr' 'libxfixes' 'libxdamage' 'libxcomposite' 'libx11' 'avahi'
         'libxi' 'xorg-xdpyinfo')
optdepends=('tk: for GUI support'
            'net-tools: for -auth guess'
            'xf86-video-dummy: for Xdummy script')
makedepends=('git')
source=("git+https://github.com/LibVNC/x11vnc.git#commit=${_commit}?signed"
        '010-x11vnc-xfc-null-ptr.patch'::'https://github.com/LibVNC/x11vnc/commit/95a10ab64c2d.patch'
        '020-x11vnc-gcc10-fix.patch'::'https://github.com/LibVNC/x11vnc/commit/a48b0b1cd887.patch'
        '030-x11vnc-scan-limit-access-to-shared-memory'::'https://github.com/LibVNC/x11vnc/commit/69eeb9f7baa1.patch'
        'x11vnc.service')
validpgpkeys=('25E71D2709955ECD4D041E03421BB3B45C6067F8') # Christian Beier
sha256sums=('SKIP'
            'd39a399d7db8e942e55639ed04a51b3c4f5d31d213d4639b1e26a44d92029403'
            '2c71af4c586eabaa11744da65916f9223b928d1fba820f117243f6c8c585f16b'
            'e9c121a0b16013059ce903ed3e7560fabc5015e3b058a3acec85d7ae7102fcf0'
            'cfb19d44e09e960e2fdb958c9258bccf23c2677715314985f7e819f1dcedb6e4')

prepare() {
	patch -d x11vnc -Np1 -i "${srcdir}/010-x11vnc-xfc-null-ptr.patch" # FS#65851
	patch -d x11vnc -Np1 -i "${srcdir}/020-x11vnc-gcc10-fix.patch"
	patch -d x11vnc -Np1 -i "${srcdir}/030-x11vnc-scan-limit-access-to-shared-memory" # FS#68930
	autoreconf -fi x11vnc
}

build() {
	cd "$pkgname"
	./configure --prefix='/usr' --mandir='/usr/share/man'
	make
}

package() {
	make -C x11vnc DESTDIR="$pkgdir" install
	install x11vnc/misc/{rx11vnc,Xdummy} -t "${pkgdir}/usr/bin"
	install -D -m644 x11vnc.service -t "${pkgdir}/usr/lib/systemd/system"
}
